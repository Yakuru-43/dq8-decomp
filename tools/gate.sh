#!/usr/bin/env bash
# The gate: nothing is committed or pushed unless this passes (CLAUDE.md).
#
#   tools/gate.sh            check what `git commit` would record (the index;
#                            with nothing staged that is HEAD)
#   tools/gate.sh --head     check HEAD itself
#   tools/gate.sh --quick    factory worktrees only: the index may touch only
#                            src/, config/*.yaml and notes/, every staged source
#                            must print MATCH with tools/verify.py, plus steps 1-2;
#                            no clean build. Writes "quick:<tree>", which the hook
#                            accepts for commits on a factory-N branch only. The
#                            full gate runs when the branch is integrated.
#
# It builds that tree from scratch in a temp dir (your iso/ and extract/
# copied in, .toolchain and .venv linked), runs `make split && make`, checks
# the six SHA-1s against the original disc, refuses game data and binaries,
# and lints every C file changed since origin/main for contrived code.
# On success it writes the checked tree id to build/gate.ok, which the
# commit/push hook (.claude/hooks/gate-guard.py) compares against.
# Exit status is non-zero on any failure.
set -uo pipefail

ROOT=$(git -C "$(dirname "$0")/.." rev-parse --show-toplevel) || exit 1
cd "$ROOT" || exit 1

QUICK=0
if [[ ${1:-} == --quick ]]; then QUICK=1; shift; fi
if [[ ${1:-} == --head ]]; then
    TREE=$(git rev-parse 'HEAD^{tree}')
    WHAT="HEAD ($(git rev-parse --short HEAD))"
else
    TREE=$(git write-tree) || { echo "gate: FAIL: the index has unmerged paths"; exit 1; }
    if [[ $TREE == $(git rev-parse 'HEAD^{tree}') ]]; then
        WHAT="HEAD ($(git rev-parse --short HEAD), nothing staged)"
    else
        WHAT="the index (HEAD $(git rev-parse --short HEAD) + staged changes)"
    fi
fi
BASE=origin/main
JOBS=${GATE_JOBS:-$(( $(nproc) > 2 ? $(nproc) - 1 : 1 ))}

# The original disc's binaries. Hard-coded so that an edit to checksum.sha1
# cannot make a broken build pass.
EXPECTED="48ebb92638560447aab9c94235b0ebee5e93bc44  build/SLES_539.74
26a2d3a66e9f9e89ea482f3815c3fc5247dd90a1  build/BIN/BATTLE.BIN
6127d0cba7bd600119f6b0d47c5562395f3af3d2  build/BIN/CASINO.BIN
275311c1e5d58572cfdc3ecad8fa6a85904ca4c5  build/BIN/MENU.BIN
1a0c5d0af311ad459f2d78432a7219ed3d016f5a  build/BIN/SHOP.BIN
1fc0bb423f022b4d77f9d8ae3612298fe17058da  build/BIN/TITLE.BIN"

fail=0
step() { printf '\n== %s\n' "$*"; }
bad() { echo "gate: FAIL: $*"; fail=1; }

echo "gate: checking $WHAT, tree ${TREE:0:12}"
rm -f build/gate.ok

# --- 1. forbidden paths and binaries -------------------------------------
step "forbidden paths and binaries"
forbidden=$(git ls-tree -r --name-only "$TREE" \
    | grep -E '^(asm|iso|extract|assets|build|linker)/|(^|/)asmfunc/' || true)
[[ -n $forbidden ]] && bad "game data or generated files in the tree:" && echo "$forbidden" | head -20
EMPTY=$(git hash-object -t tree /dev/null)
binaries=$(git diff --numstat "$EMPTY" "$TREE" | awk -F'\t' '$1 == "-" {print $3}')
binaries+=$'\n'$(git ls-tree -r --name-only "$TREE" \
    | grep -iE '\.(iso|bin|elf|o|a|so|exe|dll|dat|hd6|mvi|irx|cnf|payload|pdf|png|jpe?g|zip|7z|gz|xz)$' || true)
binaries=$(echo "$binaries" | sed '/^$/d' | sort -u)
[[ -n $binaries ]] && bad "binary files in the tree:" && echo "$binaries" | head -20
[[ $fail == 0 ]] && echo "ok"

# --- 2. lint C changed since origin/main -----------------------------------
step "lint: C files changed since $BASE"
mapfile -t changed < <(git diff --name-only --diff-filter=AMR "$BASE" "$TREE" -- \
    'src/*.c' 'src/*.cpp' 'src/*.h' 'include/*.h' | grep -v '/asmfunc/')
if (( ${#changed[@]} )); then
    LINT=$(mktemp -d)
    for f in "${changed[@]}"; do
        mkdir -p "$LINT/$(dirname "$f")"
        git cat-file blob "$(git rev-parse "$TREE:$f")" > "$LINT/$f"
    done
    if (cd "$LINT" && "$ROOT/.venv/bin/python" "$ROOT/tools/lint_contrived.py" "${changed[@]}"); then
        echo "ok (${#changed[@]} files)"
    else
        bad "contrived C (fix it, or see CLAUDE.md)"
    fi
    rm -rf "$LINT"
else
    echo "ok (no C changes)"
fi

# --- quick mode: scope and per-function verification instead of a build ----
if [[ $QUICK == 1 ]]; then
    step "quick: staged changes stay in src/, config/*.yaml, notes/"
    outside=$(git diff --cached --name-only | grep -vE '^(src/[^/]+/[^/]+\.(c|cpp|h)|config/[^/]+\.yaml|notes/.+)$' || true)
    [[ -n $outside ]] && bad "quick mode only covers function work; run the full gate for:" && echo "$outside"
    [[ -z $outside ]] && echo "ok"
    step "quick: every staged source file matches (tools/verify.py)"
    mapfile -t srcs < <(git diff --cached --name-only --diff-filter=AM -- 'src/*.c' 'src/*.cpp' | grep -v '/asmfunc/')
    for f in "${srcs[@]}"; do
        if ! git diff --quiet -- "$f"; then bad "$f has unstaged edits: stage or revert them"; continue; fi
        r=$(.venv/bin/python tools/verify.py "$f" 2>&1 | tail -1)
        [[ $r == MATCH* ]] || bad "$f: $r"
    done
    [[ $fail == 0 ]] && echo "ok (${#srcs[@]} files)"
    echo
    if [[ $fail == 0 ]]; then
        echo "quick:$TREE" > build/gate.ok
        echo "gate: PASS, quick ($WHAT)"
        exit 0
    fi
    echo "gate: FAIL, quick ($WHAT)"
    exit 1
fi

# --- 3. clean build from the tree ---------------------------------------
step "clean build: make split && make -j$JOBS"
WORK=$(mktemp -d "${TMPDIR:-/tmp}/dq8-gate.XXXXXX")
trap 'rm -rf "$WORK"' EXIT
mkdir "$WORK/repo"
git archive "$TREE" | tar -x -C "$WORK/repo"
cp -a iso extract "$WORK/repo/"
ln -s "$ROOT/.toolchain" "$WORK/repo/.toolchain"
ln -s "$ROOT/.venv" "$WORK/repo/.venv"
LOG=$ROOT/build/gate.log
mkdir -p build
if (cd "$WORK/repo" && make split && make -j"$JOBS") > "$LOG" 2>&1; then
    echo "ok (log: build/gate.log)"
else
    bad "build failed; last lines of build/gate.log:"
    tail -15 "$LOG"
fi

# --- 4. the six SHA-1s ----------------------------------------------------
step "SHA-1 of the six binaries"
if (cd "$WORK/repo" && sha1sum -c <<< "$EXPECTED"); then
    :
else
    bad "a rebuilt binary differs from the original"
fi

echo
if [[ $fail == 0 ]]; then
    echo "$TREE" > build/gate.ok
    echo "gate: PASS ($WHAT)"
    exit 0
fi
echo "gate: FAIL ($WHAT)"
exit 1

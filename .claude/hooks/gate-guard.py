#!/usr/bin/env python3
"""PreToolUse hook: block `git commit` / `git push` unless tools/gate.sh passed.

tools/gate.sh writes the tree id it checked to build/gate.ok (as "quick:<tree>"
after `gate.sh --quick`, which only counts for commits on a factory-N branch).  A commit is
allowed only when that is the tree the index holds now (what the commit would
record); a push only when it is HEAD's tree.  Anything staged or committed
after the gate ran changes the tree id, so the gate has to run again.
Also refuses `git add -A/--all/.` and `git commit -a`, which sweep in files
nobody looked at.  Exit 2 blocks the call and shows the message to the model.
"""
import json
import re
import subprocess
import sys
from pathlib import Path

GIT = r"(?:^|[;&|(]\s*|\s)git(?:\s+-C\s+\S+)?\s+"


def git(*args, cwd):
    r = subprocess.run(["git", *args], cwd=cwd, capture_output=True, text=True)
    return r.stdout.strip() if r.returncode == 0 else None


def block(msg):
    print(msg, file=sys.stderr)
    sys.exit(2)


def main():
    try:
        event = json.load(sys.stdin)
    except ValueError:
        return 0
    cmd = (event.get("tool_input") or {}).get("command") or ""
    cwd = event.get("cwd") or "."
    # commit messages and other text: heredoc bodies and quoted strings
    cmd = re.sub(r"<<-?\s*(['\"]?)(\w+)\1.*?^\s*\2\s*$", "", cmd, flags=re.S | re.M)
    cmd = re.sub(r"'[^']*'|\"(?:\\.|[^\"\\])*\"", "''", cmd)
    if re.search(GIT + r"add\s+(?:[^;&|]*\s)?(?:-A|--all|\.)(?:\s|$|[;&|])", cmd):
        block("Blocked: no `git add -A`/`git add .` here (CLAUDE.md). Stage the files you mean by name.")
    commit = re.search(GIT + r"commit\b([^;&|]*)", cmd)
    push = re.search(GIT + r"push\b", cmd)
    if not commit and not push:
        return 0
    if commit and re.search(r"\s(?:-a\b|--all\b|-\w*a\w*m\b)", commit.group(1)):
        block("Blocked: `git commit -a` commits files the gate never saw. Stage by name, run tools/gate.sh, then commit.")
    top = git("rev-parse", "--show-toplevel", cwd=cwd)
    if not top:
        return 0
    stamp = Path(top) / "build" / "gate.ok"
    passed = stamp.read_text().strip() if stamp.exists() else ""
    if commit:
        want, what = git("write-tree", cwd=top), "the staged tree"
    else:
        want, what = git("rev-parse", "HEAD^{tree}", cwd=top), "HEAD"
    if passed.startswith("quick:"):
        # gate.sh --quick: function work in a factory worktree, commits only
        branch = git("branch", "--show-current", cwd=top) or ""
        if not commit or not re.fullmatch(r"factory-\d+", branch):
            block(f"Blocked: a quick gate only covers commits on a factory-N branch. "
                  f"Run the full `tools/gate.sh`{'' if commit else ' --head'}, then retry.")
        passed = passed[len("quick:"):]
    if not passed or passed != want:
        block(f"Blocked: tools/gate.sh has not passed for {what} ({(want or '?')[:12]}). "
              f"Run `tools/gate.sh` (or `tools/gate.sh --head` before a push), fix what it reports, then retry.")
    return 0


if __name__ == "__main__":
    sys.exit(main())

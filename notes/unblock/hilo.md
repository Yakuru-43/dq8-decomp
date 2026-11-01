# Unblock: link failures (queue blocker `hilo`)

Status: done

## 2026-11-01 (night 2, Opus, branch `unblock`)

### What the family is now
`hilo` is not a relocation problem any more. funcdb gives the blocker to any
function whose last autodecomp result is `link`, i.e. every draft failed at
the link step. The 130 functions of 2026-10-13 were mostly `%hi/%lo` vs
`$gp` externs and soft-float helpers, which earlier commits already fixed
(`fix_externs()` puts hi/lo externs in `.data`, `symbol_script_for()` defines
address-named symbols, `float_protos()` prototypes float callees). The queue
had 4 `hilo` rows at the start of the night.

To see what is left, autodecomp got `--why` (each draft's compile or link
error goes to `build/why/<bin>/errors.tsv`, next to the draft) and a census
ran over every unmatched function of the main binary (dry run).
Draft-level link errors, by count: `fptodp` (rescued by `float_protos` in
other drafts of the same function), `litodp`/`dptoli`/`__floatdisf`
(s64<->float conversions in m2c drafts), `R_MIPS_LITERAL` truncation (8
functions: an int constant m2c typed as a denormal float, e.g. `1.4e-43f`,
which CodeWarrior puts in `.lit4`), and `M2C_BREAK`.

### The real family: divbyzerocheck functions (206 in the main binary)
A divide guarded by `bnez d; div; break 0, 7` is CodeWarrior's
`divbyzerocheck` option. m2c writes the guard as `if (d == 0) { M2C_BREAK(0); }`
and nothing defines `M2C_BREAK`, so every draft of these functions failed to
link (or to compile). autodecomp now drops those guards and compiles with
`-flag divbyzerocheck`, writing `// flags: -flag divbyzerocheck` on a match.
`--divides` selects the family. Result of `--divides` on the main binary:
206 functions, 0 link failures now (was every one), 2 matches straight away,
27 mismatches and 61 repaired drafts as near-misses.

### Commits
- 6c658510 tools: autodecomp drops M2C_BREAK guards, compiles with the flag;
  `--divides`, `--why`
- 8da6f840 tools: `--why` keeps the first mismatching draft as
  `build/why/<bin>/<func>.mismatch.c` (flag line included), a base for try_match
- 7af58ed0 src: func_00327A30, func_0037A7D0 (autodecomp), func_0022A880,
  func_00164550, func_00199E80, func_001F0050 (by hand from the drafts)
- c51213d5 src: func_001A3900, func_001A3750, func_001A6450, func_0022A6F0
- c1cc63b6 notes: idioms (divbyzerocheck in autodecomp; one-off compare
  bounds give `slti $at`; node pools as one inline with `goto found`), and
  notes/needs-claude/func_001A6710.md

- 5272b1f5 src: BATTLE func_00467210 (autodecomp `--bin BATTLE --divides`)
- 30348774 config: SHOP keeps D_00415EA4 (keep_funcs; needs a build of the
  new object first, then `make split && make -j`)
- 6bfa9d68 src: SHOP func_0045F640, MENU func_00469C20

**13 functions of the family match** (10 main binary, 3 overlays; 2,144 B).
Full gate, six OK, each time. Overlays: `--divides` on BATTLE 13, CASINO 28,
MENU 10, SHOP 2, TITLE 0 functions.

### Census result (dry run, main binary, code from before the fix)
5,468 functions: mismatch 1,885, repaired 1,375, size 848, m2c 615,
compile 600, **link 17**, data 5, entry inside 4, plus 119 asm functions
that match (VU0, git-ignored). After re-running `--divides` with the fix, the
queue has **11 `hilo` rows (5.2 KB)**: func_001CFDA0, func_00379510,
func_001B8800, func_001CFE60, func_0028C770, func_0023C630, func_002D2C40,
func_00378F70, func_0023EF30, func_001C01C0, func_00346020. Their draft
errors: `R_MIPS_LITERAL` (5: func_001B8800, 1CFDA0, 1CFE60, 23C630, 23EF30),
`__moddi3` from m2c's s64 sign-extension shifts (func_002D2C40: `(s8)` is
meant), `litodp`/`fptodp` s64<->float conversions (func_00346020,
func_001C01C0). Each is a draft defect to fix by hand, not a build problem.
Note: a dry run still appends to build/autodecomp_<bin>.tsv, and funcdb takes
the last line per function, so a census with old code can hide newer results.

### What the factory can take now
Queue blocker `hilo` (what is left of it) and every function whose asm has
`break 0, 7`: run `tools/autodecomp.py --divides --why`, then finish
`build/why/SLES_539.74/<func>.mismatch.c` with
`tools/try_match.py ... -- -O3 -flag divbyzerocheck`. Near-misses worth
taking first (size): func_0021AA30 (128), func_0015B7A0 (144, a bitfield
struct), func_002D4FC0 (176, cold-block placement), func_00170F00 (336),
func_0014CB70 (384), func_00244060 (400), func_00144AA0 (448).

### Open
- The 0x60-slot pool siblings in game_1A61C0.s (func_001A6360, func_001A6710,
  func_001A67D0, func_001A6AC0, ...): the original uses `beql` for every
  one-instruction `if`, we get cold blocks; C shape, -O levels and C++ don't
  change it. notes/needs-claude/func_001A6710.md. Worth a compiler-build try.
- `R_MIPS_LITERAL` drafts: autodecomp could type an extern written through
  `M2C_BITWISE(s32, ...)` as s32 instead of f32 (8 functions, not done).
- Overlay near-misses from `--divides`: BATTLE 1 mismatch + 5 repaired,
  CASINO 2 + 11, MENU 5 repaired.
- verify.py defines address-named `D_` symbols itself, so an overlay file that
  names a main-binary global verifies but fails the build until keep_funcs
  has seen its object (build, keep_funcs, split, build). Worth a line in the
  factory skill; not changed tonight.

### Next
Stage C moves on to `entry-inside` (see notes/unblock/entry-inside.md).

# Unblock: jump tables (queue blocker `jumptable`)

Status: done

## 2026-10-25 (night 1, Opus, branch `unblock`)

### Why the family failed
A `switch` that CodeWarrior compiles to a jump table puts the table in the
object's `.rodata` (alignment 16, R_MIPS_32 relocs to the function). Three
things refused that:
- `autodecomp.verify()` rejected any object with `.rodata` (`data`), and
  autodecomp skipped every function whose asm mentions `jtbl` (`jumptable`).
- The original table lives in the data segment (one big `data` subsegment per
  binary), as raw words; the build had no way to put a src file's `.rodata`
  there. splat would have linked it after the main segment's text.
- m2c only saw the function's asm, not the table, so its drafts had no
  `switch`; splat's table also runs on into the alignment zeros after it.

### What changed (commit f1eb3ff, tools)
- A src file names its table range with `// rodata: 0xSTART 0xEND` under
  `// range:` (and above `// flags:`).
- `tools/gen_configs.py`: cuts that range out of the data subsegments
  (`[START, .rodata, <file>]`, data resumes at END), main and overlays.
- `tools/postsplit.py`: splat lists the object's `.rodata` twice (its own
  segment's .rodata block, which comes first and would win, and the end of the
  data segment after every .data); both lines are replaced by one right after
  the data file that precedes START.
- `autodecomp.verify()` takes `rodata=(START, bytes)`: links `.rodata` at
  START (`--section-start`) and compares it after the code (a code diff still
  reads `mismatch`; `rodata` means the code matches but the range is wrong).
  `tools/verify.py` reads the line.
- autodecomp: `rodata_range()` / `function_tables()` derive the range from the
  asm's `%hi(jtbl_...)` refs, trimming each table to the words that point into
  the function; `with_jump_tables()` gives m2c the tables with `.L` labels;
  `--jumptables` selects the family; matches get the `// rodata:` line.
- `tools/jtbl.py <func> [--bin B] [--m2c]`: the rodata line and the m2c draft
  with a real `switch`, for the factory.

### Matches (src commits aa08014, 1d246a4, and the last src commit of the night)
autodecomp (`--jumptables`, all six binaries): func_001FA430, func_00327620,
func_003276A0. By hand: func_002C70D0, func_0035F200, func_002148E0,
func_0036D030, func_00357EF0, func_002F7830, func_002F8B50, func_0020E1A0,
BATTLE func_004601B0, CASINO func_0045ED10 (with `-flag divbyzerocheck`).
13 functions; the overlay path (BATTLE, CASINO) is proven too. Full gate:
six OK each time.

`tools/jtbl.py --diff <src>` (later tools commit) prints the table entries a
src file gets wrong when verify says RODATA; that is how func_002F8B50's
missing `case 1: break;` showed up (try_match cannot see tables).

CodeWarrior detail worth knowing: when the smallest case is a small positive
number the table starts at 0 (no subtract), so entries below it point at the
default; a negative or large smallest case is subtracted first.

### What the factory needs (in notes/idioms.md, "jumptable")
`tools/jtbl.py` for the line and the draft; table-reading tips (empty cases at
the table ends, empty `b join` stubs = re-assigning the current value, case
bodies in source order, `switch (x - 0xFA00)` from a split constant, the
`p != 0 ? ctor(p) : p` shape).

### Open sub-families (needs-claude material, not tooling)
- Inlined bool helper with a switch (func_0035F030, F0C0, F160, ED10, EE10,
  EF20, EA20?, EB00?, DE10?): a C++ `inline bool` helper gives the right shape
  but one extra `andi 0xFF` at the test; `== false`, `!`, `!= false`, int,
  s64, a bool local, `default: return false` all tried.
- `if (obj->f == 0) { switch (new+ctor per case) }` (func_0026D230, D560,
  D6B0, DB70, E1F0, E410, E640, E870, EA90, ECB0): with the ternary the case
  code matches; CodeWarrior places the switch block after the code that
  follows the if and jumps back; no C shape found yet (same family as the
  pilot's block-placement misses).
- A switch the compiler turns into a compare chain while the original has a
  table (func_00369DC0: 0x2329..0x236E range, only 8 real cases): the
  original lists more (empty) cases; which ones is unknown.
- func_002A2C20 (two switches): all but one stub match; the second table's
  entry 0 points at a separate `b return; nop` stub (a `case 0:` whose body
  compiled to nothing); `case 0: break;` and `case 0: return id;` don't give
  it. Best C in notes/needs-claude/func_002A2C20.md.
- C++ scoped lock (func_0025CCF0): a class with an inline destructor matches
  the shape but emits `.exceptix` and an out-of-line destructor that the
  linker scripts don't place; needs a decision on C++ exception sections.

### Next
The factory can take queue blocker `jumptable`. Stage C moves on to `hilo`.

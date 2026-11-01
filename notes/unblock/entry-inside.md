# Unblock: global entry points inside a function (queue blocker `entry-inside`)

Status: done

## 2026-11-01 (night 2, Opus, branch `unblock`)

### Where the family stood
128 functions on 2026-10-21; 121 of them were in overlays, where the
whole overlay sat 0x40 too low (the MWo3 header, notes/pilot-review.md). The
overlay vram fix had already cleared those, so the queue had 7 rows left
tonight, all in the main binary: _start, func_00100220, func_00100E60 (boot
and runtime code), and four game functions.

### Why the game ones failed
splat had merged a function into the one before it and left its start as an
`alabel`: each starts on a 16-byte boundary after nop padding, or after a
stub that ends in `jr`/`b`, and other code calls it. Declaring the start as a
function in config/symbol_addrs_SLES_539.74.txt splits them cleanly.

### Commits
- 9bb14eb2 config: func_00168840, func_0017A440, func_001A0C30,
  func_001F4AC0 declared `type:func` (full gate, six OK)
- 0c3a63ff src: func_00168840 (round up to 64), func_001A0C10 (autodecomp)

The split turned 4 blocked rows into 8 ordinary ones (func_001684A0 is now a
plain `jumptable` row). 2 match tonight. func_0017A420 and func_001F4AB0 are
C++ virtual tail calls (`lw t9,0x68(a0); lw t9,slot(t9); jr t9`): the
known tail-call wall (notes/needs-claude/func_00100450.md and others), not
this family.

### Gate
The family is used up: 3 rows remain, all boot/runtime code before 0x101000
(_start, func_00100220, func_00100E60). There are not 10 functions left to
match, so the plan's gate can't apply; marked done because the blocker has no
tooling cause left. Recipe for any new one: if the `alabel` follows padding
or a `jr`/`b` stub and is called from elsewhere, add
`func_X = 0xX; // type:func` to the symbol file, `make split && make -j`,
six OK.

### What the factory can take now
Queue blocker `entry-inside` is gone for game code; the 7 split rows are
blocker `none` (func_001684A0: `jumptable`).

### Next
Stage C is through its three families. Leftovers for Claude: the `beql`
pool siblings (notes/needs-claude/func_001A6710.md), the tail-call wall,
`R_MIPS_LITERAL` typing in autodecomp, `--divides` on the overlays.

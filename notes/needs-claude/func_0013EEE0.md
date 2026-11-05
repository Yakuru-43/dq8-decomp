# func_0013EEE0 — needs-claude

CLASS: n/a — mixed CPU + hand-written VU0; no C attempt applicable
(0x13B900-family precedent; VU0 block is load-bearing).

- Size: 176 B (0x13EEE0..0x13EF90), `game_13EE60.s`.
- What it does: builds a 16-byte packet. Head is CPU: a 16-iteration `sb`
  zero-fill loop on a stack buffer at `sp+0x10` (`beqz` on the constant
  address — memset-inline shape), then `swc1 $f12..$f14` stores. Middle is
  VU0 float→int conversion: `lqc2 $vf10, 0(sp)` / `vftoi4.xy` / `vftoi0.z` /
  `sqc2` back to `sp`. Tail assembles u64 words from ints with
  `dsll32/dsra32/dsll/or` pairs and `sd`s them to `0xF4($a0)` (+`lw $t2`
  reload between the two `sd`s), `lw $a2, 0x124($a0)`, `lw $t0, 0x120($a0)`.
- VU0 words: 0x13EF20..0x13EF2C (`lqc2/vftoi4.xy/vftoi0.z/sqc2`). MWCC
  never emits VU0 from C (mh2 ref "What can't come from C", VU0 bullet
  ~line 4024; weekly 2026-11-03 func_00149000 decision still open).
- Byte-exact `asm void` stub verifies MATCH:
  `src/SLES_539.74/asmfunc/func_0013EEE0.c` (`// auto: asm function
  (hand-written VU0 code...)`). Gitignored, so this row can never produce
  committed bytes.

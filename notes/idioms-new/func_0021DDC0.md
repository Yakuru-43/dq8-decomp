# Idioms-new

## Ceil-division written as a `?:` on the remainder: quotient lands in the `beql` delay slot, `+1` recomputed in the branch body
Sign: the original rounds a size up to 16-byte units as
`addiu $t, $v, K; andi $v, $t, 0xF; beql $v, $zero, L; srl $a1, $t, 4;` then, in the
fall-through block, `srl $v, $t, 4; addiu $a1, $v, 1;` and both paths merge at the
`jal`. Your C `units = (x + K) / 16; if ((x + K) % 16) units++;` instead emits the
quotient once (`srl $a1`), tests with `beqz $v0` + `nop`, and increments with
`addiu $a1, $a1, 1` — CLASS structural: wrong branch flavour and the `+1` reads the
wrong register.
Fix: write the round-up as a ternary on the remainder, with the quotient spelled out
on both arms:
```c
units = ((len + 5) % 0x10) != 0 ? (len + 5) / 0x10 + 1 : (len + 5) / 0x10;
```
CodeWarrior evaluates the condition first (so `andi` precedes the `srl`), branches to
the plain-quotient arm with `beql` (the `srl $a1` fills the delay slot), and
re-materialises `(len + 5) / 0x10` into `$v0` + `addiu` in the increment arm — it does
not CSE the division across the two arms. The shared `+5` is still computed once
(`addiu $v1`). Keep the operand unsigned (`u32`) so no sign-correction appears.
Example: src/SLES_539.74/func_0021DDC0.c
Solved: func_0021DDC0 (2026-10-31, Qwen, factory-2)

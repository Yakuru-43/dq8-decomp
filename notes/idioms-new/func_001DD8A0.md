## A `c1 0x...` word between `nop`s is a CW float intrinsic, not a branch: `sqrtf()` emits `sqrt.s`
Sign: spimdisasm prints an undecoded coprocessor-1 word as `c1 0x4` (word
`04000046` = 0x46000004) sitting between `nop`s, often right after a
`cvt.s.w`/`lwc1` producer and before an `swc1` of the same `$fN`. Reading it
as a `bc1fl` never works: no `c.xx.s` sets FCC anywhere in the function, and
both paths of the preceding branch meet at it. The mh2 catalogue calls the
same objdump output `c1 0xc0044` for `sqrt.s`.
Fix: declare the intrinsic and call it on the value — `extern f32 sqrtf(f32);`
then `x = sqrtf(x);` — MWCC emits `sqrt.s` itself, including the surrounding
nops (CW's FPU-latency scheduling). Do not write `if (x ...) ...` around it.
Example: src/SLES_539.74/func_001DD8A0.c
Solved: func_001DD8A0 2026-10-29 Qwen factory-1 (twin of func_001DD810 with
`sqrtf` replacing `func_0012A038`; the same `c1 0x4` also sits in
func_001BC430 and other script-VM nodes — check those next)

## Call-guard `beql` with `v0=0` in its delay slot: write the zero arm redundantly with `!x`
Sign: original has `jal f; beql $v0,$zero,<epilogue>; daddu $v0,$zero,$zero; <call block>
<epilogue>` — a call result tested against 0 where the *zero path branches to the shared
epilogue* (return 0) and the nonzero path *falls into* the second call. Drafting
`r = f(...); if (r == 0) { return 0; } return g(...);` gives the inverted `bnez` + a private
`b <epilogue>; daddu $v0,$zero,$zero` stub, 8 B too long (mine 156 vs 148, CLASS structural).
`if (r != 0) { r = g(...); } return r;` is worse (160 B, extra back `b`).
Fix: write it as an if/else into one local with the *redundant* zero assignment and the `!`
spelling: `if (!r) { r = 0; } else { r = g(...); } return r;` — the `!` swaps which block is
fall-through (per the mh2 "if (!x) A else B compiles as if (x) B else A" rule) and the
`r = 0;` (already true) is kept as the `beql` delay-slot `daddu $v0,$zero,$zero`. The second
call's 4th argument is still the pre-call `r` (`daddu $a3,$v0,$zero` in the second jal's
delay slot), so passing `r` works because the copy is scheduled before the call clobbers v0.
Example: src/SLES_539.74/func_001B2DC0.c
Solved: func_001B2DC0 func_001B2E60 2026-10-28 Qwen factory-1; func_001CF460
2026-10-29 Qwen factory-1 (same `if (!r) { r = 0; } else { r = g(...); }` shape,
guard on func_001CFF60's result)

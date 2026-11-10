# func_0026DAD0

CLASS structural score=41 (36 words differ, 176 vs 156 bytes) — best attempt, stable across all 5 tries.

Size 0x9C (160 B) at 0x0026DAD0, `asm/SLES_539.74/game_26DAD0.s`.

## What it does
Loads `s0 = *(s32 *)a2`, reads `s0->0x28` into `a0`; if zero, skips the four call
blocks and falls into the tail. Each block: `lw a2,flag(s0); beqz a2 →next; nop;
lw a1,0x20(s0); jal func_00278570; lw a0,0x28(s0)` (block 1 has `lw a1` in the jal
delay slot instead). Flag order 0x44, 0x50, 0x48, 0x54; a0/a1 reloaded from the
struct before every call. Tail: `sw zero 0x50, addiu v0=1, sw zero 0x44/0x48/0x54`,
`return 1`. Frame: `sd ra,0x10(sp); sq s0,0(sp)`, 0x20 frame.

## Best C (all variants land on the same diff)
```c
typedef struct { char pad0[0x20]; u32 unk20; char pad24[4]; u32 unk28;
    char pad2C[0x18]; u32 unk44; u32 unk48; char pad4C[4]; u32 unk50; u32 unk54;
} S_0026DAD0;
extern void func_00278570(u32 base, u32 ptr, u32 size);

u32 func_0026DAD0(u32 arg0, u32 arg1, S_0026DAD0 **argp) {
    S_0026DAD0 *s; u32 n;
    s = *argp;
    if (s->unk28 == 0) { goto done; }
    n = s->unk44; if (n != 0) { func_00278570(s->unk28, s->unk20, n); }
    n = s->unk50; if (n != 0) { func_00278570(s->unk28, s->unk20, n); }
    n = s->unk48; if (n != 0) { func_00278570(s->unk28, s->unk20, n); }
    n = s->unk54; if (n != 0) { func_00278570(s->unk28, s->unk20, n); }
done:
    s->unk50 = 0; s->unk44 = 0; s->unk48 = 0; s->unk54 = 0;
    return 1;
}
```

## The diff
Orig emits every call block INLINE (beqz skip-shape, jal in the fall-through).
Mine emits `bnel $a2,$zero,<far>` per block and places the three call bodies as
cold islands AFTER the tail (each `jal; nop-or-lw a1; b back`), 176 B vs 156 B.
The 4th block stays inline in both. Everything else (prologue, block 0, tail
order 50/1/44/48/54, epilogue) is byte-identical.

## What I tried
1. Nested `if (unk28) { 4 ifs }` + tail — islands.
2. Guard clause + `goto done` — identical.
3. Explicit `goto nXX` over each body (per MH2 "Branch layout" / Chara_CreateTask
   pattern, index entry read 2026-10-27) — identical.
4. Named `u32 n` for the flag, u32 fields — identical.
5. `(void)` arg casts vs none — identical.

MH2 entries consulted: "Branch layout: returns, shared blocks, alignment nops"
(block-placement bullets, incl. "if-body placed after the function's last block
and jumped back to" — cause is a goto to a block after an explicit return, which
I don't have). Also notes/idioms.md "Guard clauses" and "loop with a top guard".

Likely something about call-frequency heuristics or the shared callee makes CW
sink blocks 1–3; try: different callee return type, `#pragma push`/loop hints,
or check a neighboring TU file that calls func_00278570 in the matched style.

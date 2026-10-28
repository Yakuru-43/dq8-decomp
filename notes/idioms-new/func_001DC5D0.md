## Unrolled same-shape stores: reuse one `Struct *sl` local, hoist floats via named temps
Sign: k unrolled `if (e->type == 3) *(f32 *)(e->ptr + 4) = v;` tests over an array of
8-byte `{s32 type; char *ptr;}` entries (diff: mine 8 B short per entry, no
`addiu $a0,$s0,N` delay slot, loads strength-reduced to `0xC($s0)`/`0x14($s0)`).
The original keeps the entry *address*: `addiu $a0,$s0,8` in the branch delay slot and
`lw $v0,4($a0)` in the body block.
Fix: assign each entry through one reused pointer local (`sl = slots;` /
`sl = slots + 1;` ... before each test) — CW then materializes the base as `addiu` and
loads the member via `4($a0)`. Write the *last* entry direct (`slots[3].type`) when the
original's last block loads `0x1C($s0)` directly (the addiu got folded away). For float
values: declare `f32 val = vals[i];` on the line just before the test — CW hoists the
`lwc1` out of the body into the test block (before the branch) or into the branch delay
slot as a plain `beq` (not `beql`); keeping the value load in the body puts `lwc1` after
the body's `lw` and is 0 B off but shifts the whole tail. Slot 0's value being the
call result (int, `sw` from `$v0`) vs the float arm (`swc1` from `$f0`) is a real type
difference, keep `*(s32 *)(sl->ptr + 4)` for it.
Example: src/SLES_539.74/func_001DC5D0.c
Solved: func_001DC5D0 2026-10-28 Qwen factory-1

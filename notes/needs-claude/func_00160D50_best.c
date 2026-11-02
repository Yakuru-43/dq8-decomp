// CLASS structural score=103 (91 words differ, 532 vs 484 bytes) -- best attempt 2026-11-02 ~22:02, factory-1 (2 tries this session, not stuck: session time ran out; 113 -> 103, but mine still 48 B too big)
// range: 0x160D50 0x160F40
// flags: -flag divbyzerocheck
//
// Findings for the next session (the draft below IS the 103-score attempt):
//  1. FIXED shapes (keep as written below): the entry guards are ONE `||`:
//     `if (idx < 0 || idx >= 16) { p = 0; } else { p = &D_003F7900[idx]; ... }`
//     -- this is what makes CW emit `bltz a0,F04 / slti at,a0,0x10; beqz at,F04` with the
//     shared cold stub `b DC4; daddu s0,zero`, and it schedules `daddu s1,a2` into the
//     bltz delay slot. A nested `if (idx >= 0) { if (idx < 16) ... }` puts the copy and
//     the p=0 init inline instead (wrong).
//  2. FIXED: field_78 must be read as `D_003F7900[idx].field_78` (fresh array access) --
//     `p->field_78` folds to `lbu v0,0x78(s0)`, the original recomputes lui/addiu
//     D_003F7978 + addu v1. field_00 test keeps `p->field_00` (lbu 0(s0) ✓).
//  3. FIXED: `if ((u32)n > 1)` (unsigned! sltiu+ bnez $at), `rounded = size;` right
//     before it (its daddu a1,s2 lands in the bnez delay slot). Div guards, mflo/mfhi,
//     `mult $a1,$v1,$a0`, the whole sema block and the func_0011BFB0 arg order now match
//     the original word-for-word in the aligned diff.
//  4. FIXED: type dispatch is a `switch (t)` written `case 0:` (sema), then
//     `case 2: case 4: case 1:` (shared), `default:` -- idioms.md "Compare chain on
//     constants": tests come out reverse-source = 1,4,2, beql 0 with lw sema in the
//     delay slot, default `b stub; addiu s1,-1` inline, bodies cold in source order
//     (sema E44, shared E94). The if/else-if chain gave tests 4,2 and the sema inline (113).
//  5. REMAINING (why mine is +48 B): my return stub is duplicated -- original has ONE
//     `b F1C; daddu v0,s1` reached from all four paths (sema tail `b epi; sw s1,6C(s0)`,
//     shared tail falls through after `lw s1,6C(s0)`). Mine keeps extra `daddu v0,s1` +
//     `b` pairs around +0x190-0x1B0. The mode switch also: original is beql 2/1/0 with
//     the store (addu / lw / sw) hoisted into each delay slot, mine is beq+nop with the
//     stores in the bodies, and my case blocks sit in a different order. Try `switch (mode)`
//     cases exactly 0,1,2,default (what I have) but check whether removing the explicit
//     `t = p->field_01` temp (switch on p->field_01 directly) or moving the `default:`
//     arm's `ret` free of the break frees registers for the hoists.
//  6. Try tools/permute.py func_00160D50 --run 600 on the 103 draft once the size is
//     right; before that it just permutes a wrong size.
//  7. Globals: D_003DFBA8 (sema id, extern s32 -- as in src/SLES_539.74/func_001617E0.c),
//     D_003E02E0 (counter, extern s32), D_003F7900 (Slot[], sibling src/SLES_539.74/
//     func_00161380.c has the Slot layout; 0x7C stride, field_00/01/78 u8, 04/08/10/6C/70 s32).
//     D_003F7978 in the asm is the same array + 0x78 (see 2).
//     func_0011BFB0(s32,s32,s32) -- arg 1 is p->field_04, arg 2 the ORIGINAL size ($s2),
//     arg 3 mode; the M2C_UNK WaitSema/SignalSema(s32) decls match the siblings.
#include "common.h"

typedef struct {
    u8 field_00;
    u8 field_01;
    u8 field_02;
    u8 field_03;
    s32 field_04;
    s32 field_08;
    s32 pad0C;
    s32 field_10;
    u8 pad14[0x58];
    s32 field_6C;
    s32 field_70;
    u8 pad74[4];
    u8 field_78;
    u8 pad79[3];
} Slot;

extern s32 D_003DFBA8;
extern s32 D_003E02E0;
extern Slot D_003F7900[];
M2C_UNK WaitSema(s32);
M2C_UNK SignalSema(s32);
extern s32 func_0011BFB0(s32, s32, s32);

s32 func_00160D50(s32 idx, s32 size, s32 mode) {
    Slot *p;
    s32 n;
    s32 rounded;
    s32 limit;
    s32 q;
    s32 r;
    s32 ret;
    s32 t;

    if (idx < 0 || idx >= 16) {
        p = 0;
    } else {
        p = &D_003F7900[idx];
        if (p->field_00 == 0) {
            p = 0;
        } else if (D_003F7900[idx].field_78 != 0) {
            p = 0;
        }
    }
    if (p == 0) {
        return -1;
    }
    n = p->field_70;
    rounded = size;
    if ((u32)n > 1) {
        q = (u32)size / (u32)n;
        if ((u32)size % (u32)n != 0) {
            q = q + 1;
        }
        rounded = q * n;
    }
    t = p->field_01;
    switch (t) {
    case 0:
        if (D_003DFBA8 >= 0) {
            WaitSema(D_003DFBA8);
        }
        D_003E02E0 = D_003E02E0 + 1;
        r = func_0011BFB0(p->field_04, size, mode);
        if (D_003DFBA8 >= 0) {
            SignalSema(D_003DFBA8);
        }
        D_003E02E0 = D_003E02E0 - 1;
        if (r >= 0) {
            p->field_6C = r;
        }
        ret = r;
        break;
    case 2:
    case 4:
    case 1:
        limit = p->field_10 * n;
        if (t == 2) {
            limit = p->field_08;
        }
        switch (mode) {
        case 0:
            p->field_6C = rounded;
            break;
        case 1:
            p->field_6C = p->field_6C + rounded;
            break;
        case 2:
            p->field_6C = limit + rounded;
            break;
        default:
            break;
        }
        if ((u32)limit < (u32)p->field_6C) {
            p->field_6C = limit;
        }
        ret = p->field_6C;
        break;
    default:
        ret = -1;
        break;
    }
    return ret;
}

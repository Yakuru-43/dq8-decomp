// CLASS structural score=47 (44 words differ, 256 vs 268 bytes; first diff +0x40) — best attempt 2026-11-03, factory-2
// Prologue, args[0] ternary, n3 ternary, call 1 and the c.lt.s/bc1fl tail all
// match. 3 instructions short: kind>=2 float arm merges into a bnel delay slot
// (want bnez + out-of-line lwc1 + b with cvt.s.w in its delay slot + ap phi
// copies in $a0), second objs[i] load must be index-first, tail stub shared.
// See func_0023E330.md for the full diff analysis.
// range: 0x23E330 0x23E440
#include "common.h"

typedef union Value {
    s32 i;
    f32 f;
} Value;

typedef struct {
    s32 tag;
    Value value;
} Arg;

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u32 objs[1];
} ObjList;

extern ObjList *D_003E0B24;

extern void func_001EA0A0(u32, s32, s32);
extern void func_00288A70(u32, s32, f32);

s32 func_0023E330(Arg *args, s32 kind) {
    Arg *ap;
    f32 val;
    s32 n2;
    u32 obj;
    s32 n3;
    s32 i;

    i = (args[0].tag == 1) ? (s32)args[0].value.f : args[0].value.i;
    obj = *(u32 *)((u32)D_003E0B24 + 0x10 + i * 4);
    if (obj == 0) {
        return 0;
    }
    n2 = args[1].value.i;
    val = -1.0f;
    ap = &args[2];
    n3 = 0;
    if (kind >= 2) {
        if (ap->tag == 0) {
            val = (f32)ap->value.i;
        } else {
            val = ap->value.f;
        }
        ap = &args[3];
    }
    if (kind >= 3) {
        n3 = (ap->tag == 1) ? (s32)ap->value.f : ap->value.i;
    }
    func_001EA0A0(obj, n2, n3);
    if (val < 0.0f) {
        return 1;
    }
    func_00288A70(D_003E0B24->objs[i], 1, val);
    return 1;
}

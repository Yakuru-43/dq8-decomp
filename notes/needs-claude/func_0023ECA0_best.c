// range: 0x23ECA0 0x23ED80
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
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ void *field8;
} ScriptMgr;

extern ScriptMgr *D_003E0B24;

void func_001EA0A0(void *, s32, s32);
void func_00288A70(void *, s32, f32);

s32 func_0023ECA0(Arg *args, s32 kind) {
    void *target;
    s32 v0val;
    Arg *ap;
    f32 f;
    s32 a2;

    target = D_003E0B24->field8;
    if (target == 0) {
        return 0;
    }
    v0val = args[0].value.i;
    f = -1.0f;
    ap = &args[1];
    a2 = 0;
    if (kind >= 2) {
        if (ap->tag != 0) {
            f = ap->value.f;
        } else {
            f = (f32)ap->value.i;
        }
        ap++;
    }
    if (kind >= 3) {
        a2 = (ap->tag == 1) ? (s32)ap->value.f : ap->value.i;
    }
    func_001EA0A0(target, v0val, a2);
    if (f >= 0.0f) {
        func_00288A70(D_003E0B24->field8, 1, f);
    }
    return 1;
}

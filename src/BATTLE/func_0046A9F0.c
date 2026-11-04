// range: 0x46A9F0 0x46AB10
#include "common.h"

union TaggedValue {
    s32 i;
    f32 f;
};

struct TaggedVal {
    s32 tag;
    union TaggedValue v;
};

struct BattleObj {
    struct TaggedVal a;
    struct TaggedVal b;
    struct TaggedVal c;
};

typedef struct BattleGlobal4 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 field_04;
} BattleGlobal4;

s32 func_18AA10(s32, s32, s32, s32, f32);           /* extern */
s32 func_18AA70(s32, s32, s32, s32, f32);           /* extern */
s32 func_18AAD0(s32, s32, f32);                     /* extern */
s32 func_19ACC0(s32);                               /* extern */
extern BattleGlobal4 *D_003E1BB0;

s32 func_0046A9F0(struct BattleObj *o, s32 arg1) {
    s32 a;
    s32 b;
    s32 c;
    struct TaggedVal *v;

    func_19ACC0(D_003E1BB0->field_04 + 0x68E0);
    if (arg1 == 3) {
        a = (o->a.tag == 1) ? (s32)o->a.v.f : o->a.v.i;
        v = (struct TaggedVal *)((char *)o + 8);
        if (o->b.tag == 1) {
            b = (s32)v->v.f;
        } else {
            b = v->v.i;
        }
        c = (o->c.tag == 1) ? (s32)o->c.v.f : o->c.v.i;
        if (a == 0) {
            func_18AA70(D_003E1BB0->field_04, b, c, a, 1.0f);
        } else {
            func_18AA10(D_003E1BB0->field_04, b, c, a, 1.0f);
        }
    } else {
        a = (o->a.tag == 1) ? (s32)o->a.v.f : o->a.v.i;
        func_18AAD0(D_003E1BB0->field_04, a, 1.0f);
    }
    return 1;
}

// range: 0x1C7150 0x1C7240
#include "common.h"

M2C_UNK func_001A7790(s32, f32 *, s32, s32, f32);
extern s32 D_003E06F4;

struct TaggedVal {
    s32 tag;
    union {
        s32 i;
        f32 f;
    } val;
};

union Buf4 {
    f32 f[4];
    u128 q;
};

s32 func_001C7150(char *arg0) {
    union Buf4 buf;
    s32 a2;
    s32 a3;
    f32 f12;
    struct TaggedVal *t;

    buf.q = 0;
    buf.f[0] = *(s32 *)arg0 == 0 ? (f32)*(s32 *)(arg0 + 4)
                                 : *(f32 *)(arg0 + 4);
    t = (struct TaggedVal *)(arg0 + 8);
    buf.f[1] = *(s32 *)(arg0 + 8) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x10);
    buf.f[2] = *(s32 *)(arg0 + 0x10) == 0 ? (f32)t->val.i : t->val.f;
    buf.f[3] = 1.0f;
    t = (struct TaggedVal *)(arg0 + 0x18);
    a2 = *(s32 *)(arg0 + 0x18) == 1 ? (s32)t->val.f : t->val.i;
    t = (struct TaggedVal *)(arg0 + 0x20);
    a3 = *(s32 *)(arg0 + 0x20) == 1 ? (s32)t->val.f : t->val.i;
    f12 = *(s32 *)(arg0 + 0x28) == 0 ? (f32)*(s32 *)(arg0 + 0x2C)
                                     : *(f32 *)(arg0 + 0x2C);
    func_001A7790(D_003E06F4, buf.f, a2, a3, f12);
    return 1;
}

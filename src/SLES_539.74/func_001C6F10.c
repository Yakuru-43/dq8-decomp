// range: 0x1C6F10 0x1C7000
#include "common.h"

M2C_UNK func_001A73D0(s32, f32 *, s32 *);
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

s32 func_001C6F10(char *arg0) {
    union Buf4 buf;
    union Buf4 buf2;
    struct TaggedVal *t;

    buf.q = 0;
    buf.f[0] = *(s32 *)arg0 == 0 ? (f32)*(s32 *)(arg0 + 4)
                                 : *(f32 *)(arg0 + 4);
    t = (struct TaggedVal *)(arg0 + 8);
    buf.f[1] = *(s32 *)(arg0 + 8) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x10);
    buf.f[2] = *(s32 *)(arg0 + 0x10) == 0 ? (f32)t->val.i : t->val.f;
    buf.f[3] = 1.0f;
    buf2.q = 0;
    t = (struct TaggedVal *)(arg0 + 0x18);
    buf2.f[0] = *(s32 *)(arg0 + 0x18) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x20);
    buf2.f[1] = *(s32 *)(arg0 + 0x20) == 0 ? (f32)t->val.i : t->val.f;
    buf2.f[2] = *(s32 *)(arg0 + 0x28) == 0 ? (f32)*(s32 *)(arg0 + 0x2C)
                                           : *(f32 *)(arg0 + 0x2C);
    buf2.f[3] = 1.0f;
    func_001A73D0(D_003E06F4, buf.f, (s32 *)buf2.f);
    return 1;
}

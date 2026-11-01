// range: 0x1B49D0 0x1B4BE0
#include "common.h"

extern void func_001E0590(f32 *);
extern void func_00131188(f32 *, s32, s32);
extern s32 func_00168160(void);
extern void func_0018A180(s32, s32, f32 *);
extern void func_0018A1C0(s32);

struct TaggedVal {
    s32 tag;
    union {
        s32 i;
        f32 f;
    } val;
};

s32 func_001B49D0(char *arg0) {
    f32 buf[12];
    struct TaggedVal *t;
    s32 val;
    s32 ret;

    if (*(s32 *)arg0 == 1) {
        val = (s32)*(f32 *)(arg0 + 4);
    } else {
        val = *(s32 *)(arg0 + 4);
    }

    if (val == 0) {
        ret = func_00168160();
        func_0018A1C0(ret);
        return 1;
    }

    func_001E0590(buf);
    func_00131188(buf, 0, 0x30);

    t = (struct TaggedVal *)(arg0 + 8);
    buf[0] = *(s32 *)(arg0 + 8) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x10);
    buf[1] = *(s32 *)(arg0 + 0x10) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x18);
    buf[2] = *(s32 *)(arg0 + 0x18) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x20);
    buf[3] = *(s32 *)(arg0 + 0x20) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x28);
    buf[4] = *(s32 *)(arg0 + 0x28) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x30);
    buf[5] = *(s32 *)(arg0 + 0x30) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x38);
    buf[6] = *(s32 *)(arg0 + 0x38) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x40);
    buf[7] = *(s32 *)(arg0 + 0x40) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x48);
    buf[8] = *(s32 *)(arg0 + 0x48) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x50);
    buf[9] = *(s32 *)(arg0 + 0x50) == 0 ? (f32)t->val.i : t->val.f;
    t = (struct TaggedVal *)(arg0 + 0x58);
    buf[10] = *(s32 *)(arg0 + 0x58) == 0 ? (f32)t->val.i : t->val.f;
    buf[11] = *(s32 *)(arg0 + 0x60) == 0 ? (f32)*(s32 *)(arg0 + 0x64)
                                          : *(f32 *)(arg0 + 0x64);

    ret = func_00168160();
    func_0018A180(ret, 1, buf);
    return 1;
}

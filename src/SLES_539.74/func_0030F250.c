// range: 0x30F250 0x30F350
#include "common.h"

struct Rec {
    s64 f0;
    s64 f8;
};

struct Unit {
    char pad0[0x10];
    s16 f10;
    s16 f12;
    char pad14[0xE0 - 0x14];
    struct Rec recs[39];
    u8 f350;
};

struct Node {
    s32 f0;
    s32 f4;
};

struct Out {
    char pad0[0x2C];
    char f2C[0x1E8 - 0x2C];
    struct Node *f1E8;
    char pad1EC[0xA8C - 0x1EC];
    s32 fA8C;
    s32 fA90;
    void *fA94;
};

struct Table {
    void *base;
};

extern struct Table D_00453D10 __attribute__((section(".data")));
extern s32 D_003E1168;
extern M2C_UNK D_003D0870 __attribute__((section(".data")));

extern void func_0029C600(void *arg0);
extern void func_0030EFD0(void *arg0);
extern void func_00300CB0(s32 arg0, M2C_UNK *arg1, s32 arg2);
extern s32 func_00310410(s32 arg0, void *arg1);
extern void func_0030F350(void *arg0);
extern void func_0030DCC0(void *arg0, u32 arg1);
extern void func_0030ECD0(void *arg0, void *arg1);
extern void func_0030F360(void *arg0, void *arg1);

void func_0030F250(void *arg0, struct Out *out, struct Unit *ai) {
    struct Rec buf[42];
    struct Rec *src;
    struct Rec *dst;
    s32 i;

    src = ai->recs;
    dst = buf;
    for (i = 42; i > 0; i = i - 1) {
        *dst = *src;
        dst = dst + 1;
        src = src + 1;
    }
    func_0029C600(out);
    if (D_00453D10.base == 0) {
        func_00300CB0(0, &D_003D0870, 0x409);
        func_0030F360(arg0, out);
        return;
    }
    func_0030EFD0(out);
    D_003E1168 = out->f1E8->f4;
    out->fA94 = ai;
    out->fA90 = func_00310410(out->fA8C, out->fA94);
    func_0030F350(out->f2C);
    func_0030DCC0(out, ai->f350);
    func_0030ECD0(ai->recs, buf);
    func_0030F360(arg0, out);
}

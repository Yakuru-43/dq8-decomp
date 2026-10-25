// range: 0x30F700 0x30F7E0
#include "common.h"

struct Result {
    f32 f0;
    s8 f4;
};

struct Item {
    s32 n;
    s64 *elems;
};

struct Out {
    char pad0[0xA8C];
    s32 fA8C;
    s32 fA90;
};

struct Table {
    char *base;
};

extern struct Table D_00453D10 __attribute__((section(".data")));
extern M2C_UNK D_003D0870 __attribute__((section(".data")));

extern char *func_0030F840(char *arg0);
extern struct Item *func_0030F7E0(char *arg0, s32 arg1);
extern void func_00300CB0(s32 arg0, M2C_UNK *arg1, s32 arg2);
extern void func_0030EF10(void *arg0);
extern void func_0030D600(void *arg0, void *arg1, void *arg2, s32 arg3,
                          s32 arg4, s32 arg5, s32 arg6, s32 arg7);
extern f32 func_00356880(void *arg0);

u8 func_0030F700(struct Out *out, s32 idx) {
    struct Result res;
    char work[376];
    char *container;
    struct Item *item;
    u8 ret;

    container = func_0030F840(D_00453D10.base);
    if (container == 0) {
        func_00300CB0(0, &D_003D0870, 0x37D);
        return 0;
    }
    item = func_0030F7E0(container, idx);
    if (item == 0) {
        func_00300CB0(0, &D_003D0870, 0x37F);
        return 0;
    }
    func_0030EF10(work);
    func_0030D600(&res, work, &item->elems, item->n, out->fA8C, out->fA90,
                  out->fA90, 0);
    if (func_00356880(&res) != 0.0f) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

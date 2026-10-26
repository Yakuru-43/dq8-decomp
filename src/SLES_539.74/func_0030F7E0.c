// range: 0x30F7E0 0x30F840
#include "common.h"

struct Container {
    s32 n;
    s32 offs[1];
};

extern M2C_UNK D_003D0920 __attribute__((section(".data")));

extern void func_00300CB0(s32 arg0, M2C_UNK *arg1, s32 arg2);

char *func_0030F7E0(struct Container *c, s32 arg1) {
    if ((arg1 < 0) || (arg1 >= c->n)) {
        func_00300CB0(0, &D_003D0920, 0x6B);
        return 0;
    }
    return (char *) c + c->offs[arg1];
}

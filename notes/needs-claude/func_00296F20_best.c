// range: 0x296F20 0x296F60
#include "common.h"

extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));

s32 func_002989C0(void *, s32);

u8 func_00296F20(void *arg0, u8 arg1) {
    u32 index;
    char *base;

    index = func_002989C0(&D_0042CDB0, arg1);
    base = (char *) arg0 + index * 4;
    return *(u8 *) (base + 0x160);
}

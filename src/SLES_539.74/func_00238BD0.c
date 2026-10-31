// range: 0x238BD0 0x238C00
// auto: m2c, verified byte-exact
#include "common.h"

extern void func_00238E70(void *arg0, s32 arg1, s32 arg2, s32 arg3);

struct ByteBits {
    u8 low : 1;
    u8 val : 7;
};

void func_00238BD0(void *arg0, s32 arg1) {
    struct ByteBits *bits = (struct ByteBits *)arg0;
    s32 a3 = arg1;

    if (M2C_FIELD(arg0, s32 *, 0) & 1) {
        arg1 = M2C_FIELD(arg0, s32 *, 4);
    } else {
        arg1 = (u8)bits->val;
    }
    func_00238E70(arg0, arg1, 0, a3);
}

// range: 0x177080 0x1770C0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001770C0(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_0021FD90(M2C_UNK *);                   /* extern */
extern s32 D_0040F4FC __attribute__((section(".data")));
extern M2C_UNK D_0040F540 __attribute__((section(".data")));

void func_00177080(s32 arg0) {
    func_0021FD90(&D_0040F540);
    func_001770C0(arg0, D_0040F4FC, 0xD0);
}

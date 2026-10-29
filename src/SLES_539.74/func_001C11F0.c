// range: 0x1C11F0 0x1C1240
#include "common.h"

M2C_UNK func_001AC1B0(void *, s32, s32, s32);
extern M2C_UNK D_00411ED0 __attribute__((section(".data")));

s32 func_001C11F0(char *arg0) {
    s32 a1;
    s32 a2;
    s32 a3;
    f32 tmp;

    if (*(s32 *)arg0 == 1) {
        tmp = *(f32 *)(arg0 + 4);
        a1 = (s32)tmp;
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    a2 = *(s32 *)(arg0 + 0xC);
    if (*(s32 *)(arg0 + 0x10) == 1) {
        tmp = *(f32 *)(arg0 + 0x14);
        a3 = (s32)tmp;
    } else {
        a3 = *(s32 *)(arg0 + 0x14);
    }
    return func_001AC1B0(&D_00411ED0, a1, a2, a3);
}

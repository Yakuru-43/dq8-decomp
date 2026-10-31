// range: 0x1C1460 0x1C14B0
#include "common.h"

M2C_UNK func_001AC2F0(void *, s32, s32);
extern M2C_UNK D_00411ED0 __attribute__((section(".data")));

s32 func_001C1460(char *arg0) {
    s32 a1;
    s32 a2;
    f32 tmp;

    if (*(s32 *)arg0 == 1) {
        tmp = *(f32 *)(arg0 + 4);
        a1 = (s32)tmp;
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    if (*(s32 *)(arg0 + 8) == 1) {
        tmp = *(f32 *)(arg0 + 0xC);
        a2 = (s32)tmp;
    } else {
        a2 = *(s32 *)(arg0 + 0xC);
    }
    return func_001AC2F0(&D_00411ED0, a1, a2);
}

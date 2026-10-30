// range: 0x2C0180 0x2C0200
#include "common.h"

extern M2C_UNK D_0044EE30 __attribute__((section(".data")));

void *func_002C0180(s32 arg0, s32 arg1) {
    if (arg0 < 0 || arg0 >= 4) {
        return 0;
    }
    if (arg1 < 0 || arg1 >= 2) {
        return 0;
    }
    return (char *)&D_0044EE30 + arg0 * 0xB0 + arg1 * 0x58;
}

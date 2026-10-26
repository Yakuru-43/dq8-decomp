// range: 0x225B40 0x225B80
#include "common.h"

void func_00225B40(void *arg0, s32 arg1) {
    if (arg1 < 0) {
        arg1 = M2C_FIELD(arg0, s16 *, 0x8) - 1;
    }
    if (M2C_FIELD(arg0, s16 *, 0x8) - 1 < arg1) {
        arg1 = 0;
    }
    M2C_FIELD(arg0, s16 *, 0x2) = arg1;
}

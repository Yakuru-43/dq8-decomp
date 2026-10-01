// range: 0x181D80 0x181DD0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00181D80(void *arg0, s32 arg1) {
    if (arg1 == 0) {
        M2C_FIELD(arg0, s32 *, 0x300) = 0xFF;
    }
    if (arg1 == 1) {
        M2C_FIELD(arg0, s32 *, 0x304) = 0xFF;
    }
    if (arg1 == 2) {
        M2C_FIELD(arg0, s32 *, 0x308) = 0xFF;
    }
}

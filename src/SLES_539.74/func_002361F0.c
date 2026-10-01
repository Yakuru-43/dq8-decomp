// range: 0x2361F0 0x236210
// auto: m2c, verified byte-exact
#include "common.h"

void func_002361F0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x200) = arg1;
    if (M2C_FIELD(arg0, s32 *, 0x200) == 0) {
        M2C_FIELD(arg0, s32 *, 0x208) = 0;
    }
}

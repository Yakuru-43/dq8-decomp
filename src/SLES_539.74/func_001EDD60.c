// range: 0x1EDD60 0x1EDD70
// auto: m2c, verified byte-exact
#include "common.h"

void func_001EDD60(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xF4) = arg1;
}

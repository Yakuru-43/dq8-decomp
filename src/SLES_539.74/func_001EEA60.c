// range: 0x1EEA60 0x1EEA70
// auto: m2c, verified byte-exact
#include "common.h"

void func_001EEA60(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x74) = arg1;
}

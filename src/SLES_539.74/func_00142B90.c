// range: 0x142B90 0x142BC0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00142B90(void *arg0, s32 *arg1) {
    if ((arg1 != NULL) && (M2C_FIELD(arg0, s32 *, 0xF20) != 0)) {
        M2C_FIELD(arg0, s32 **, 0x36B0) = arg1;
        M2C_FIELD(arg0, s32 *, 0x36B8) = (s32) *M2C_FIELD(arg0, s32 **, 0x36B0);
    }
}

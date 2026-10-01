// range: 0x376300 0x376340
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001813D0();                              /* extern */

void func_00376300(s32 arg0, s32 arg1) {
    M2C_FIELD(func_001813D0(), s32 *, 0x1C) = arg0;
    M2C_FIELD(func_001813D0(), s32 *, 0x20) = arg1;
}

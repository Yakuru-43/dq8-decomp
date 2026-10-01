// range: 0x377330 0x377370
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
s64 func_00308460(s32, M2C_UNK);                    /* extern */

s32 func_00377330(void) {
    return (((s64) (func_00308460(func_001814D0(), 0x1C) << 0x30) >> 0x30) >= 4) & 0xFF;
}

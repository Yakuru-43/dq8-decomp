// range: 0x260880 0x2608B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00201CC0();                                /* extern */
s32 func_00372D60(s32);                             /* extern */

s32 func_00260880(void) {
    return func_00372D60(func_00201CC0()) != 0;
}

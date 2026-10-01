// range: 0x35E8B0 0x35E8F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
s32 func_002D05A0(s32);                             /* extern */
s32 func_00304A20(s32);                             /* extern */

f32 func_0035E8B0(void) {
    return (f32) func_00304A20(func_002D05A0(func_001814D0()));
}

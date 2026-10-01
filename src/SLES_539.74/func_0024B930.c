// range: 0x24B930 0x24B990
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00242D20(M2C_UNK);                         /* extern */

s64 func_0024B930(s32 arg0, M2C_UNK arg1) {
    s32 temp_v0;

    temp_v0 = func_00242D20(arg1);
    if ((temp_v0 >= 0) && (temp_v0 < 0x180)) {
        return (s64) ((s64) M2C_FIELD((arg0 + temp_v0), s8 *, 0x6D) << 0x3E) >> 0x3F;
    }
    return 0;
}

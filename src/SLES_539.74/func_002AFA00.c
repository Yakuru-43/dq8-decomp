// range: 0x2AFA00 0x2AFA50
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001007A0();                            /* extern */

s32 func_002AFA00(s32 arg0, s64 arg1) {
    if ((arg0 != 0) && (((s64) (arg1 << 0x30) >> 0x30) > 0)) {
        func_001007A0();
    }
    return arg0;
}

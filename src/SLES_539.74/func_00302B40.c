// range: 0x302B40 0x302B90
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001007A0();                            /* extern */
extern s32 D_003E10E4;

s32 func_00302B40(s32 arg0, s64 arg1) {
    if (arg0 != 0) {
        D_003E10E4 = 0;
        if (((s64) (arg1 << 0x30) >> 0x30) > 0) {
            func_001007A0();
        }
    }
    return arg0;
}

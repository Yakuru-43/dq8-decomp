// range: 0x351910 0x351960
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0025F5A0();                            /* extern */
extern s8 D_003E13A4;
extern s8 D_003E13A8;
extern s16 D_003E13AC;
extern s16 D_003E13B0;

void func_00351910(s32 arg0, s64 arg1) {
    D_003E13A4 = (s8) arg1;
    D_003E13A8 = 0;
    if (((s64) (arg1 << 0x38) >> 0x38) != 0) {
        func_0025F5A0();
    }
    D_003E13B0 = 0;
    D_003E13AC = -1;
}

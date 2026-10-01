// range: 0x2113F0 0x211430
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0018F130();                                /* extern */
s32 func_00211430(s32);                             /* extern */
extern s32 D_003E08DC;

s32 func_002113F0(s32 arg0) {
    if (arg0 != 0) {
        return func_00211430(func_0018F130());
    }
    return D_003E08DC + 0x10;
}

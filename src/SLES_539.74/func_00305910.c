// range: 0x305910 0x305950
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00167A80();                                /* extern */
M2C_UNK func_0020C360(s32);                         /* extern */
M2C_UNK func_00371BB0(s32, M2C_UNK);                /* extern */
extern s8 D_003E1140;

void func_00305910(s32 arg0) {
    func_00371BB0(func_00167A80(), 2);
    func_0020C360(arg0);
    D_003E1140 = 0;
}

// range: 0x203180 0x2031D0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002025C0();                                /* extern */
M2C_UNK func_002031D0(s32, s32);                    /* extern */

void func_00203180(s32 arg0, s32 arg1) {
    func_002031D0(arg0, -func_002025C0());
    func_002031D0(arg0, arg1);
}

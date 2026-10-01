// range: 0x379440 0x379470
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_00379470(s32, s32);                    /* extern */

void func_00379440(s32 arg0) {
    func_00379470(func_002D34C0(), arg0);
}

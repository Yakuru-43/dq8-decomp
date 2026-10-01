// range: 0x378BE0 0x378C10
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00201C90();                                /* extern */
M2C_UNK func_00311800(s32, s32);                    /* extern */

void func_00378BE0(s32 arg0) {
    func_00311800(func_00201C90(), arg0);
}

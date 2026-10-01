// range: 0x204200 0x204250
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00201DB0();                                /* extern */
M2C_UNK func_00206D70(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_00204200(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    func_00206D70(func_00201DB0(), arg1, arg2, arg3);
}

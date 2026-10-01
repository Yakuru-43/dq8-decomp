// range: 0x204000 0x204040
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00201DB0();                                /* extern */
M2C_UNK func_00206B80(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_00204000(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_00206B80(func_00201DB0(), arg1, arg2);
}

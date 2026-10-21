// range: 0x460FB0 0x460FE0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00460F20(s32);                         /* extern */
M2C_UNK func_2F6960();                              /* extern */

s32 func_00460FB0(s32 arg0) {
    func_2F6960();
    func_00460F20(arg0);
    return arg0;
}

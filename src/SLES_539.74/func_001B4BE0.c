// range: 0x1B4BE0 0x1B4C10
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00168160();                                /* extern */
M2C_UNK func_0018A1C0(s32);                         /* extern */

s32 func_001B4BE0(void) {
    func_0018A1C0(func_00168160());
    return 1;
}

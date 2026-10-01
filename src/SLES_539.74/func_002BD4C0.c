// range: 0x2BD4C0 0x2BD500
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0018E640(s32);                             /* extern */
s32 func_00192170();                                /* extern */
extern M2C_UNK func_002BD510 __attribute__((section(".data")));

s32 func_002BD4C0(void) {
    s32 var_v0;

    var_v0 = func_0018E640(func_00192170()) != 0;
    if (var_v0 != 0) {
        var_v0 = &func_002BD510 != NULL;
    }
    return var_v0 & 0xFF;
}

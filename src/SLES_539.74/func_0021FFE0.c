// range: 0x21FFE0 0x220030
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001FF2F0();                                /* extern */
M2C_UNK func_00220030(s32, s32);                    /* extern */

void func_0021FFE0(s32 arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = func_001FF2F0() - arg1;
    if (var_a1 < 0) {
        var_a1 = 0;
    }
    func_00220030(arg0, var_a1);
}

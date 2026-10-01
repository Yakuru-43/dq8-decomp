// range: 0x2B0B10 0x2B0BE0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
s32 func_003089E0(s32, M2C_UNK);                    /* extern */

s32 func_002B0B10(void) {
    s32 var_s0;

    var_s0 = 0;
    if (func_003089E0(func_001814D0() + 0x470, 0xB9) != 0) {
        var_s0 = 3;
    } else if ((func_003089E0(func_001814D0() + 0x470, 0xA6) != 0) && (func_003089E0(func_001814D0() + 0x470, 0xA7) != 0) && (func_003089E0(func_001814D0() + 0x470, 0xA8) != 0)) {
        var_s0 = 2;
    } else if (func_003089E0(func_001814D0() + 0x470, 0xA1) != 0) {
        var_s0 = 1;
    }
    return var_s0;
}

// range: 0x21FD40 0x21FD90
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0021FED0(s8 *);                        /* extern */
s32 func_00264240();                                /* extern */

s32 func_0021FD40(s8 *arg0) {
    if (func_00264240() != 0) {
        return 1;
    }
    if (*arg0 != 0) {
        func_0021FED0(arg0);
        return 2;
    }
    return 0;
}

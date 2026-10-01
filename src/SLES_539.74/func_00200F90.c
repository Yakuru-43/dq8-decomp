// range: 0x200F90 0x200FD0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00202530();                                /* extern */
s32 func_002BA7D0();                                /* extern */

s32 func_00200F90(void) {
    if (func_00202530() < 2) {
        return 0;
    }
    return func_002BA7D0() != 0;
}

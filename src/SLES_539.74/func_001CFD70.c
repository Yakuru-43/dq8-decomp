// range: 0x1CFD70 0x1CFDA0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001A2160();                                /* extern */
M2C_UNK func_001D0E70();                            /* extern */

s32 func_001CFD70(void) {
    func_001D0E70();
    return func_001A2160() != 0;
}

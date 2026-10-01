// range: 0x2F6960 0x2F69B0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_002DEC30();                            /* extern */
M2C_UNK func_002F69B0();                      /* extern */
M2C_UNK func_002FF2B0();                         /* extern */

char *func_002F6960(char *arg0) {
    func_002DEC30();
    func_002FF2B0(arg0 + 0xC0);
    func_002F69B0(arg0);
    M2C_FIELD(arg0, s32 *, 0xF0) = 0;
    M2C_FIELD(arg0, s32 *, 0xF4) = 0x1BF;
    return arg0;
}

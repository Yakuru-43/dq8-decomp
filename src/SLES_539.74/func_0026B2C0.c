// range: 0x26B2C0 0x26B320
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0026A3C0();                            /* extern */
M2C_UNK func_00276F20(char *);                      /* extern */

char *func_0026B2C0(char *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0xB0) = -1;
    func_0026A3C0();
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
    func_00276F20(arg0 + 0xD0);
    M2C_FIELD(arg0, s32 *, 0xC4) = 0;
    M2C_FIELD(arg0, s32 *, 0xC0) = 0;
    return arg0;
}

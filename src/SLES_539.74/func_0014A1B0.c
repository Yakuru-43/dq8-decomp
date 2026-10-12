// range: 0x14A1B0 0x14A210
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0014A030();                            /* extern */

void func_0014A1B0(char *arg0, char *arg1) {
    if (M2C_FIELD(arg0, s8 *, 0x2B) == 0) {
        M2C_FIELD(arg1, s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0x60);
        M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x70);
        M2C_FIELD(arg1, s128 *, 0x20) = (s128) M2C_FIELD(arg0, s128 *, 0x80);
        M2C_FIELD(arg1, s128 *, 0x30) = (s128) M2C_FIELD(arg0, s128 *, 0x90);
    } else {
        func_0014A030();
    }
}

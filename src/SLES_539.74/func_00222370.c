// range: 0x222370 0x2223C0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_002FF2B0(char *, s8);                  /* extern */

void func_00222370(char *arg0, s8 arg1) {
    s8 temp_a1;

    M2C_FIELD(arg0, s8 *, 0x1F29) = arg1;
    temp_a1 = M2C_FIELD(arg0, s8 *, 0x1F29);
    if ((temp_a1 == 0) || (temp_a1 == 0xB)) {
        func_002FF2B0(arg0 + 0xC0, temp_a1);
    }
}

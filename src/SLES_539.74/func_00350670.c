// range: 0x350670 0x3506B0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_003506B0(char *);                      /* extern */

void func_00350670(char *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = -1;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    func_003506B0(arg0 + 0xC);
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

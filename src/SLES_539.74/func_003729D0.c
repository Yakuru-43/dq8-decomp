// range: 0x3729D0 0x372A10
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0025B3A0(s16);                         /* extern */

void func_003729D0(void *arg0) {
    func_0025B3A0(M2C_FIELD(arg0, s16 *, 2));
    M2C_FIELD(arg0, s8 *, 0x24) = 0;
    M2C_FIELD(arg0, s16 *, 0x64) = -1;
}

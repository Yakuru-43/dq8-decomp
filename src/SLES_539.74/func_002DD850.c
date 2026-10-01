// range: 0x2DD850 0x2DD8A0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(void *, void *, M2C_UNK);     /* extern */

void func_002DD850(void *arg0, void *arg1) {
    func_00130FD0(arg1, arg0, 0x1C);
    M2C_FIELD(arg1, u16 *, 0x1C) = (u16) M2C_FIELD(arg0, u16 *, 0x20);
}

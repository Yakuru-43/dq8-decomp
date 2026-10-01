// range: 0x1D2400 0x1D2480
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */

void func_001D2400(char *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    func_00131188(arg0 + 8, 0, 0x40);
    func_00131188(arg0 + 0x48, 0, 0x10);
    func_00131188(arg0 + 0x58, 0, 0x10);
    func_00131188(arg0 + 0x68, 0, 0x10);
    func_00131188(arg0 + 0x78, -1, 0x10);
}

// range: 0x2030C0 0x2030F0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0();                         /* extern */

void func_002030C0(char *arg0) {
    func_001340C0(arg0 + 0xA70);
    M2C_FIELD(arg0, s32 *, 0xA68) = 0;
    M2C_FIELD(arg0, s32 *, 0xA6C) = 0;
}

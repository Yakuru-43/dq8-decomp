// range: 0x14A710 0x14A740
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0013C1C0();                         /* extern */

void func_0014A710(char *arg0) {
    func_0013C1C0(arg0 + 0x60);
    M2C_FIELD(arg0, s8 *, 0x29) = 1;
}

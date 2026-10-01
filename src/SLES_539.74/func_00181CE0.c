// range: 0x181CE0 0x181D30
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188();       /* extern */

void func_00181CE0(char *arg0) {
    func_00131188(arg0 + 0x20, 0, 0x60);
    func_00131188(arg0 + 0x290, 0, 0x60);
    M2C_FIELD(arg0, s8 *, 0x288) = 0;
}

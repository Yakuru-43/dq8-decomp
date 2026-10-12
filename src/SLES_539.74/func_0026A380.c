// range: 0x26A380 0x26A3C0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0013E080(char *);                      /* extern */
M2C_UNK func_0013E090(char *);                      /* extern */

void func_0026A380(char *arg0) {
    M2C_FIELD(arg0, s128 *, 0x60) = 0;
    M2C_FIELD(arg0, s128 *, 0x70) = 0;
    func_0013E090(arg0 + 0x80);
    func_0013E080(arg0 + 0x90);
    M2C_FIELD(arg0, s128 *, 0xA0) = 0;
}

// range: 0x22EF90 0x22EFF0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0013E100(char *, char *, char *);      /* extern */

void func_0022EF90(char *arg0, char *arg1) {
    if (M2C_FIELD(arg0, s8 *, 0x2C) == 0) {
        M2C_FIELD(arg1, s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0x60);
        M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x70);
        M2C_FIELD(arg1, s128 *, 0x20) = (s128) M2C_FIELD(arg0, s128 *, 0x80);
        M2C_FIELD(arg1, s128 *, 0x30) = (s128) M2C_FIELD(arg0, s128 *, 0x90);
    } else {
        func_0013E100(arg1, arg0 + 0x30, arg0);
    }
}

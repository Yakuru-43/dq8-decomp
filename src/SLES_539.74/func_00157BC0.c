// range: 0x157BC0 0x157C00
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00157BC0(char *arg0, char *arg1) {
    M2C_FIELD(arg1, s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0);
    M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x10);
    M2C_FIELD(arg1, s128 *, 0x20) = (s128) M2C_FIELD(arg0, s128 *, 0x20);
    M2C_FIELD(arg1, s128 *, 0x30) = (s128) M2C_FIELD(arg0, s128 *, 0x30);
    M2C_FIELD(arg1, s128 *, 0x40) = (s128) M2C_FIELD(arg0, s128 *, 0x40);
    M2C_FIELD(arg1, s128 *, 0x50) = (s128) M2C_FIELD(arg0, s128 *, 0x50);
    return 6;
}

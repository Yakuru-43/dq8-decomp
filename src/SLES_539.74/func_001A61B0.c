// range: 0x1A61B0 0x1A61C0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_001A61B0(char *arg0, char *arg1) {
    M2C_FIELD(arg1, s128 *, 0x70) = (s128) M2C_FIELD(arg0, s128 *, 0x10);
    return 0;
}

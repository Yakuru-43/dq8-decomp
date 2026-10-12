// range: 0x349610 0x349640
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00349610(char *arg0) {

    if (!(M2C_FIELD(arg0, s32 *, 0x28) != 0)) {
        return;
    }

    M2C_FIELD(arg0, s8 *, 0x44) = 1;
    M2C_FIELD(arg0, s32 *, 0x34) = 0x3F800000;
    M2C_FIELD(arg0, s8 *, 0x38) = 1;
}

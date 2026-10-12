// range: 0x242A30 0x242A50
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00242A30(char *arg0, s32 arg1) {

    if (!(arg1 != 0)) {
        return;
    }

    M2C_FIELD(arg0, s32 *, 4) = arg1;
}

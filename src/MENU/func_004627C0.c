// range: 0x4627C0 0x462800
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_004627C0(s32 arg0, s32 arg1) {
    if (arg0 == 0) {
        return 0;
    }
    if ((arg1 != 1) && (arg1 != 3)) {
        return 0;
    }
    return 1;
}

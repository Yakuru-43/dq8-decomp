// range: 0x210AE0 0x210B40
#include "common.h"

s32 func_00210AE0(s32 *arg0, s32 arg1) {
    if (arg0 == 0) {
        return 3;
    }
    if (arg0[0] == 0 || arg0[1] != 2) {
        return 1;
    }
    if (arg0[2] == 0 || !(arg0[4] < arg1)) {
        return 0;
    }
    return 2;
}

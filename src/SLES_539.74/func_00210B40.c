// range: 0x210B40 0x210BA0
#include "common.h"

s32 func_00210B40(s32 *arg0, s32 arg1) {
    if (arg0 == 0) {
        return 0;
    }
    if (arg0[0] == 0 || arg0[1] != 2) {
        return 0;
    }
    if (arg1 == 0 || arg0[6] == 0) {
        return 1;
    }
    return 0;
}

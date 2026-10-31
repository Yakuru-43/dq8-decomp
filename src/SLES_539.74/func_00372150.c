// range: 0x372150 0x372180
#include "common.h"

s32 func_00372150(s32 *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 6)) {
        return arg0[arg1];
    }
    return 0;
}

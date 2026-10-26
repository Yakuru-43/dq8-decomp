// range: 0x24E110 0x24E140
#include "common.h"

extern s32 func_00122C68(s32, s32, s32, s32, s32, s32, s32);

s32 func_0024E110(s32 *arg0) {
    return func_00122C68(1, arg0[0], arg0[1], arg0[2], arg0[3], arg0[4], arg0[5]);
}

// range: 0x297B80 0x297B90
#include "common.h"

extern s32 D_003E0E6C;

s32 func_00297B80(void) {
    s32 ret = D_003E0E6C + 1;
    D_003E0E6C = ret;
    return ret;
}

// range: 0x207D60 0x207D90
#include "common.h"

extern s16 D_003A5260[];

s16 func_00207D60(s32 arg0) {
    if (arg0 < 0) {
        return -1;
    }
    return D_003A5260[arg0];
}

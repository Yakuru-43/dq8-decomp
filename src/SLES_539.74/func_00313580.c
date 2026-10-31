// range: 0x313580 0x3135C0
#include "common.h"

extern s32 D_003AD818[];

s32 func_00313580(s32 arg0) {
    if (arg0 >= 0 && arg0 < 3) {
        return D_003AD818[arg0];
    }
    return 0;
}

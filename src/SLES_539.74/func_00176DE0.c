// range: 0x176DE0 0x176E20
#include "common.h"

extern s32 D_003E03B8;

s32 func_00176DE0(s32 arg0) {
    if (arg0 >= 0 && arg0 < 2) {
        return *(&D_003E03B8 + arg0);
    }
    return 0;
}

// range: 0x1D2370 0x1D23B0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s32 func_001D2370(s32 arg0, s32 arg1, s32 arg2) {
    if ((arg1 >= 0) && (arg1 < 8)) {
        *(s32 *) (arg0 + (arg1 * 0x88)) = arg2;
        return 1;
    }
    return 0;
}

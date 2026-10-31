// range: 0x374B70 0x374B90
#include "common.h"

extern char *D_003E0874;

s16 func_00374B70(s32 arg0) {
    if (arg0 == 0) {
        return *(s16 *)(D_003E0874 + 4);
    }
    return *(s16 *)(D_003E0874 + 6);
}

// range: 0x30FE50 0x30FEC0
#include "common.h"

extern s32 func_00310050(void *ai, s32 kind, s32 a, s32 b);

/* tries kind 2 first, then kind 0x42 */
s32 func_0030FE50(void *ai, s32 a, s32 b)
{
    if (func_00310050(ai, 2, a, b) != 0) {
        return 1;
    }
    return func_00310050(ai, 0x42, a, b);
}

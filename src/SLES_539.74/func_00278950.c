// range: 0x278950 0x278980
// Returns 7 only for a zero state whose mode field (offset 0x14) is not 3;
// every other case gives 8.
#include "common.h"

extern u32 D_003E0D98;

s32 func_00278950(s32 state) {
    if (state == 0) {
        if (*(u32 *)(D_003E0D98 + 0x14) == 3) {
            return 8;
        }
        return 7;
    }
    return 8;
}

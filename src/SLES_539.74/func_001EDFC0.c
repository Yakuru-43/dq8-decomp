// range: 0x1EDFC0 0x1EDFF0
#include "common.h"

s32 func_001EF2E0(void);
extern s32 D_003E0788;

s32 func_001EDFC0(void) {
    if (func_001EF2E0()) {
        return 1;
    } else {
        D_003E0788 = 0;
    }
    return 1;
}

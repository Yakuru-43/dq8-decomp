// range: 0x300C70 0x300CB0
#include "common.h"

s32 func_00300C70(s32 arg0, f32 fparg0) {
    f32 limit;

    limit = 180.0f;
    if (arg0 == 0x23) {
        limit = 160.0f;
    }
    if (fparg0 <= limit) {
        return 1;
    }
    return 0;
}

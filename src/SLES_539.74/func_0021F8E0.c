// range: 0x21F8E0 0x21F970
#include "common.h"

extern s32 func_002E6770(void *arg0, s32 arg1);

s32 func_0021F8E0(void *arg0) {
    s32 best;
    s32 i;

    if (arg0 == 0) {
        return 0;
    }
    best = 0;
    i = 0;
    do {
        if (best < func_002E6770(arg0, i)) {
            best = func_002E6770(arg0, i);
        }
    } while (++i < 20);
    return best;
}

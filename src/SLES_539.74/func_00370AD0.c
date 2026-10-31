// range: 0x370AD0 0x370B30
#include "common.h"

extern s32 func_00370B30(void);

s32 func_00370AD0(s32 *arg0) {
    s32 v0;
    s32 v1;

    if (arg0[1] == 0) {
        return 0;
    }
    v0 = func_00370B30();
    if (v0 != 0) {
        v1 = arg0[3];
        if (v1 != 0) {
            if (v0 == v1) {
                return 1;
            }
        }
    }
    return 0;
}

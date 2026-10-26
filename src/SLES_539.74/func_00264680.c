// range: 0x264680 0x2646C0
#include "common.h"

s32 func_00264680(M2C_UNK *arg0) {
    s32 field;

    if (arg0 == 0) {
        return 0;
    }
    field = *(s32 *)((char *)arg0 + 0x11C4);
    if (field <= -1) {
        if (field != -2) {
            return 0;
        }
    }
    return 1;
}

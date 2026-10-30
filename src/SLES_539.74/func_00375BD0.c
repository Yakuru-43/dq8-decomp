// range: 0x375BD0 0x375C10
#include "common.h"

s32 func_00375BD0(char *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = *(s32 *)(arg0 + 4);
    if (temp_v1 == 0) {
        return 0;
    }
    if (arg1 >= 0) {
        if (arg1 < (s32)*(u8 *)arg0) {
            return temp_v1 + (arg1 << 3);
        }
    }
    return 0;
}

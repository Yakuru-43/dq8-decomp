// range: 0x1EBDC0 0x1EBE00
#include "common.h"

s32 func_001EBDC0(char *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = *(s32 *)(arg0 + 0x204);
    if (temp_v1 == 0) {
        return 0;
    }
    if (arg1 >= 0) {
        if (arg1 < *(s32 *)(arg0 + 0x200)) {
            return temp_v1 + (arg1 << 3);
        }
    }
    return 0;
}

// range: 0x3439E0 0x343A10
#include "common.h"

s32 func_003439E0(char *arg0) {
    s8 v1;

    v1 = *(s8 *)(arg0 + 5);
    if (v1 == 0x6C) {
        return 1;
    }
    if (v1 == 0x6D) {
        return 2;
    }
    return 0;
}

// range: 0x240500 0x240570
#include "common.h"

s32 func_00240500(char *arg0, s32 arg1) {
    char *p;

    if (arg1 != 3) {
        return 0;
    }
    if (*(s32 *)(arg0 + 0) == 3) {
        *(s32 *)(*(char **)(arg0 + 4) + 4) = 0;
    }
    p = arg0 + 8;
    if (*(s32 *)p == 3) {
        *(s32 *)(*(char **)(p + 4) + 4) = 0;
    }
    if (*(s32 *)(arg0 + 0x10) == 3) {
        *(s32 *)(*(char **)(arg0 + 0x14) + 4) = 0;
    }
    return 1;
}

// range: 0x1DE3B0 0x1DE410
#include "common.h"

s32 func_001DE3B0(char *arg0) {
    char *p;

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

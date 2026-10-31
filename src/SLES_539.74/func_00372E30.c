// range: 0x372E30 0x372E60
#include "common.h"

s32 func_00372E30(char *arg0, s32 arg1) {
    s32 *ptr;

    if (*(s32 *)(arg0 + 0xC) == 0) {
        return 1;
    }
    ptr = *(s32 **)(arg0 + 8);
    if (ptr != NULL) {
        return *ptr == arg1;
    }
    return 1;
}

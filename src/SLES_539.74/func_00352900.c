// range: 0x352900 0x352940
#include "common.h"

extern char *func_0016D5B0(char *, s32);

s32 func_00352900(char *arg0) {
    char *temp_v0;

    temp_v0 = func_0016D5B0(arg0, 0x20);
    if (temp_v0 == NULL) {
        return -1;
    }
    if (*(s32 *)(temp_v0 + 0x510) <= 0) {
        return -1;
    }
    return *(s32 *)(temp_v0 + 0x4F4);
}

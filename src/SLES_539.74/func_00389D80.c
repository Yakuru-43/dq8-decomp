// range: 0x389D80 0x389DA0
#include "common.h"

void func_00389D80(char *arg0, s32 arg1, s8 arg2) {
    if (0 < arg1) {
        *(s16 *)(arg0 + 6) = (s16)arg1;
        *(s8 *)(arg0 + 8) = arg2;
    }
}

// range: 0x358A90 0x358AD0
#include "common.h"

void func_00358A90(s32 *arg0, char *arg1, s32 arg2, s8 arg3) {
    s32 i;
    s32 *p;
    s32 target;

    i = 0;
    p = arg0;
    do {
        target = *(s32 *)(arg1 + 0x54C);
        if (*p == target) {
            *(s8 *)(arg2 + (s32)p + 0x20) = arg3;
        }
        i++;
        p += 9;
    } while (i < 0x63);
}

// range: 0x1A5940 0x1A59E0
#include "common.h"

extern s32 func_001ABCA0(s32, s32, char *, void *);
extern void func_0013B7B0(char *, void *, char *);

s32 func_001A5940(char *arg0, char *arg1) {
    u32 sp30[3];
    s32 temp_v1;

    if (func_001ABCA0(*(s32 *)(arg1 + 0x40), *(s32 *)(arg0 + 0x20), arg0 + 0x2C, sp30) != 0) {
        func_0013B7B0(arg1 + 0x70, sp30, arg0 + 0x10);
        temp_v1 = *(s32 *)(arg0 + 0x24);
        if (temp_v1 >= 0 && *(s32 *)(arg1 + 0x44) >= temp_v1) {
            *(s32 *)(arg1 + 0x44) = 0;
            return 0;
        }
        if (temp_v1 > 0) {
            *(s32 *)(arg1 + 0x44) = *(s32 *)(arg1 + 0x44) + 1;
        }
        return 1;
    }
    return 0;
}

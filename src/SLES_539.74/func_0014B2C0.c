// range: 0x14B2C0 0x14B3C0
#include "common.h"

extern s128 D_003A0D20;
extern s128 D_003A0D30;

s32 func_0014B2C0(char *arg0, char *arg1) {
    char *p;

    if (*(s32 *)arg0 == 0 || *(s16 *)(arg0 + 4) == 0) {
        return 0;
    }
    *(s128 *)arg1 = 0;
    *(s32 *)arg1 = *(s16 *)(arg0 + 4) | 0x30000000;
    *(s32 *)(arg1 + 4) = *(s32 *)arg0;
    p = arg1 + 0x10;
    if (*(s8 *)(arg0 + 6) != 0) {
        *(s128 *)p = 0;
        *(s32 *)p = 0x10000001;
        *(s32 *)(p + 8) = 0x01000101;
        *(s32 *)(p + 0xC) = 0x6C010052;
        *(s128 *)(p + 0x10) = *(s128 *)(arg0 + 0x20);
        p += 0x20;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        *(s128 *)p = D_003A0D20;
        *(s128 *)(p + 0x10) = D_003A0D30;
        *(s64 *)(p + 0x20) = *(s64 *)(*(s32 *)(arg0 + 0xC) + 0x38);
        *(s64 *)(p + 0x28) = 6;
        p += 0x30;
    }
    *(s128 *)p = 0;
    *(s32 *)p = 0x60000000;
    p += 0x10;
    return (p - arg1) / 16;
}

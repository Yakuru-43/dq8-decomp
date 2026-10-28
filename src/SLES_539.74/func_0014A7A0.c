// range: 0x14A7A0 0x14A7E0
#include "common.h"

void func_0014A7A0(char *arg0, char *arg1) {
    s128 *ptr;

    ptr = *(s128 **)(arg0 + 0x1C);
    if (ptr == 0) {
        *(s32 *)(arg1 + 8) = 0x3F800000;
        *(s32 *)(arg1 + 4) = 0x3F800000;
        *(s32 *)(arg1 + 0) = 0x3F800000;
        *(s32 *)(arg1 + 0xC) = 0;
    } else {
        *(s128 *)arg1 = *ptr;
    }
}

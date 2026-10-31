// range: 0x3633F0 0x363410
#include "common.h"

void func_003633F0(char *arg0) {
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 0xC) = 0x3F800000;
    *(s128 *)(arg0 + 0x10) = *(s128 *)(arg0 + 0);
}

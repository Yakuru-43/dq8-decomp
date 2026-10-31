// range: 0x14B280 0x14B2C0
#include "common.h"

s32 func_0014B280(char *arg0, char *arg1) {
    *(s128 *)arg1 = 0;
    *(s32 *)arg1 = 0x60000001;
    *(s32 *)(arg1 + 8) = 0x01000101;
    *(s32 *)(arg1 + 0xC) = 0x6C010052;
    *(s128 *)(arg1 + 0x10) = *(s128 *)(arg0 + 0x20);
    return 2;
}

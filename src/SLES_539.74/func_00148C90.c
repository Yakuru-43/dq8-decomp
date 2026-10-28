// range: 0x148C90 0x148D10
#include "common.h"

s32 func_00148C90(char *arg0, char *arg1) {
    char *temp_a3;

    temp_a3 = *(char **)(arg0 + 0xF20);
    if (temp_a3 == NULL) {
        return 0;
    }
    if ((temp_a3 + 0x14) == 0) {
        return 0;
    }

    *(s128 *)(arg1 + 0) = 0;
    *(s32 *)(arg1 + 8) = 0x01000101;
    *(s128 *)(arg1 + 0x10) = *(s128 *)(temp_a3 + 0xB0);
    *(s128 *)(arg1 + 0x20) = *(s128 *)(temp_a3 + 0xC0);
    *(s128 *)(arg1 + 0x30) = *(s128 *)(temp_a3 + 0xD0);
    *(s128 *)(arg1 + 0x40) = *(s128 *)(temp_a3 + 0xE0);
    *(s128 *)(arg1 + 0x50) = *(s128 *)(temp_a3 + 0x170);
    *(s32 *)(arg1 + 0xC) = 0x6C050018;
    *(s32 *)(arg1 + 0) = 0x60000005;

    return 6;
}

// range: 0x1FA840 0x1FA870
#include "common.h"

void func_001FA840(char *arg0) {
    s32 i;

    for (i = 0; i < *(s32 *)(arg0 + 0x210); i++) {
        *(s32 *)(arg0 + (i << 3) + 0x214) = 0;
        *(s32 *)(arg0 + (i << 3) + 0x218) = 0;
    }
}

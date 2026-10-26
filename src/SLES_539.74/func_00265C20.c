// range: 0x265C20 0x265C50
#include "common.h"

void func_00265C20(char *arg0) {
    s32 i;

    for (i = 0; i < *(s32 *)arg0; i++) {
        *(u32 *)(arg0 + (i << 5) + 0x1C) = 0xBF800000;
    }
}

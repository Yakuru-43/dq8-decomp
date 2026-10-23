// range: 0x210390 0x2103D0
#include "common.h"

s32 func_00210390(void *a0) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 30; i++) {
        if (*(char *)((char *)a0 + 0x6BF0 + i * 0x50) != 0) {
            count++;
        }
    }
    return count;
}

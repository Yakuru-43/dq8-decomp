// range: 0x283D70 0x283DC0
#include "common.h"

extern s32 func_00282E60(s32);

s32 func_00283D70(void **arg0) {
    void *cursor;
    s32 sum;

    cursor = *arg0;
    sum = 0;
    while (cursor != 0) {
        sum += func_00282E60((s32)cursor + 0x10);
        cursor = *(void **)cursor;
    }
    return sum;
}

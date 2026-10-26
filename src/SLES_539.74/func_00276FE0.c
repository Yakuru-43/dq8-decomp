// range: 0x276FE0 0x277020
#include "common.h"

void func_00276FE0(void *arg0, s32 arg1, u128 *arg2) {
    s32 count;
    u128 *items;

    if (arg1 >= 0) {
        count = *(s32 *)((char *)arg0 + 0x0);
        if (arg1 < count) {
            items = *(u128 **)((char *)arg0 + 0x4);
            items[arg1] = *arg2;
        }
    }
}

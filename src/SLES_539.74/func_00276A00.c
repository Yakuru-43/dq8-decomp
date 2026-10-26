// range: 0x276A00 0x276A40
#include "common.h"

void func_00276A00(void *arg0, s32 arg1, u128 *arg2) {
    s32 count;
    u128 *items;

    if (arg1 >= 0) {
        count = *(s32 *)((char *)arg0 + 0x14);
        if (arg1 < count) {
            items = *(u128 **)((char *)arg0 + 0x18);
            *arg2 = items[arg1];
        }
    }
}

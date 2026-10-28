// range: 0x208800 0x208870
#include "common.h"

void func_00208800(char *arg0, s16 arg1, s8 arg2, s8 arg3) {
    s32 idx;
    void *ptr;
    char *base;

    idx = *(s32 *)(arg0 + 0x5874);
    if (idx < 0) {
        ptr = 0;
    } else {
        ptr = arg0 + idx * 0x6C + 0x5790;
    }
    if (ptr != 0) {
        if (*(u8 *)ptr != 0) {
            base = arg0 + idx * 6;
            *(s16 *)(base + 0x5868) = arg1;
            *(s8 *)(base + 0x586A) = arg2;
            *(s8 *)(base + 0x586B) = arg3;
            *(s16 *)(base + 0x586C) = 1;
        }
    }
}

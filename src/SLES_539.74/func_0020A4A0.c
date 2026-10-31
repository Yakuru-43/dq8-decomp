// range: 0x20A4A0 0x20A4E0
#include "common.h"

void func_0020A4A0(void *arg0, s32 arg1, s32 arg2) {
    s32 idx;
    void *slot;

    idx = *(s32 *)((char *)arg0 + 0x5874);
    if (idx < 0) {
        slot = 0;
    } else {
        slot = (char *)arg0 + idx * 0xC0 + 0x5610;
    }
    if (slot != 0) {
        *(s32 *)((char *)slot + 4) = arg1;
        *(s32 *)((char *)slot + 0xC) = arg2;
        *(s32 *)((char *)slot + 8) = arg2;
    }
}

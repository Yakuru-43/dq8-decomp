// range: 0x2E6780 0x2E67B0
#include "common.h"

struct Entry {
    /* 0x00 */ u8 pad_00[0x1798];
    /* 0x1798 */ s32 slots[20];
};

void func_002E6780(struct Entry *arg0, s32 arg1, s32 arg2) {
    s32 inRange;

    if (arg1 < 0) {
        return;
    }
    inRange = arg1 < 20;
    if (inRange == 0) {
        return;
    }
    arg0->slots[arg1] = arg2;
}

// range: 0x2E68D0 0x2E6900
#include "common.h"

struct Entry {
    /* 0x00 */ u8 pad_00[0x1770];
    /* 0x1770 */ u8 bytes[20];
};

s32 func_002E68D0(struct Entry *arg0, s32 arg1) {
    s32 inRange;

    if (arg1 < 0) {
        return 0;
    }
    inRange = arg1 < 20;
    if (inRange == 0) {
        return 0;
    }
    return arg0->bytes[arg1];
}

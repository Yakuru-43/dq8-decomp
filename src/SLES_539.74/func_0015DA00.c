// range: 0x15DA00 0x15DB40
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct Unk15DA00 {
    /* 0x000 */ u8 gap000[0xC];
    /* 0x00C */ s32 width;
    /* 0x010 */ u8 gap010[0x118];
    /* 0x128 */ s32 mode;
} Unk15DA00;

s32 func_0015DA00(Unk15DA00 *arg0, s32 arg1, s32 *arg2) {
    s32 n;
    s32 r;

    *arg2 = 0;
    if ((arg1 & 0xF0) == 0x10) {
        n = (arg0->width - 4) / 6;
        switch (arg1) {
        case 0x11:
            n = n / 2 * 2 - 2;
            break;
        case 0x13:
            n = n / 4 * 4 - 4;
            break;
        }
    } else {
        if (arg0->mode > 0) {
            n = (arg0->width - 4) / 6;
        } else {
            n = (arg0->width - 4) / 4;
        }
        switch (arg1) {
        case 4:
            n = n / 2 * 2 - 4;
            *arg2 = 2;
            break;
        case 3:
            r = 1 - n / 3;
            n = r - r * 4;
            break;
        }
    }
    return n;
}

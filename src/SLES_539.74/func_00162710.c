// range: 0x162710 0x1627E0
#include "common.h"

typedef struct {
    s32 field_00;
    u8 pad04[0x3C];
} Entry;

extern s32 D_003E030C;
extern s32 D_003E0310;
extern s32 D_003E0314;
extern s32 D_003E0318;
extern Entry D_003F6D00[];

void func_00162710(s32 arg0, s32 arg1, s32 arg2) {
    s32 rem;
    s32 q;
    s32 i;

    D_003E030C = 0;
    for (i = 0; i < 48; i++) {
        D_003F6D00[i].field_00 = 0;
    }
    if (arg1 != 1 && arg1 != 2) {
        return;
    }
    rem = arg0 & 0x3F;
    if (rem != 0) {
        arg0 += 0x40 - rem;
    }
    D_003E030C = arg0;
    D_003E0314 = arg0;
    if (arg1 == 1) {
        D_003E0314 = arg0 - 0x40;
    }
    if (arg2 < 0) {
        D_003E0310 = 0;
    } else {
        q = arg2 / 4 * 4 - 4;
        if (arg1 == 1) {
            D_003E0310 = arg0 - (q << 4);
        } else {
            D_003E0310 = arg0 + (q << 4);
        }
    }
    D_003E0318 = arg1;
}

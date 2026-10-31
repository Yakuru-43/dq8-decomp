// range: 0x222D60 0x222E10
// flags: -flag divbyzerocheck
#include "common.h"

s32 func_0022A840(s32, s32);                         /* extern */

struct Obj {
    /* 0x00 */ u8 pad_00[0x2];
    /* 0x02 */ s16 n2;
    /* 0x04 */ s32 total;
    /* 0x08 */ s16 n8;
};

s32 func_00222D60(struct Obj *arg0) {
    s32 acc;
    s32 count;
    s32 r;
    s32 q;

    if (arg0->n2 == 0) {
        return arg0->total % 10;
    }
    count = arg0->n8 - 1;
    acc = arg0->total;
    while (arg0->n2 < count) {
        r = func_0022A840(10, count);
        q = acc / r;
        acc = acc - q * r;
        count = count - 1;
    }
    return acc / func_0022A840(10, arg0->n2);
}

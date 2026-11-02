// range: 0x2804C0 0x2805B0
#include "common.h"

extern "C" {

struct Unk88 {
    /* 0x00 */ s32 field_00;
    /* 0x04 */ s32 field_04;
    /* 0x08 */ s32 field_08;
    /* 0x0C */ s32 field_0C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    /* 0x3C */ s32 field_3C;
    /* 0x40 */ s32 field_40[8];
    /* 0x60 */ s32 field_60[8];
    /* 0x80 */ s32 field_80;
    /* 0x84 */ s32 field_84;

    Unk88() {}
}; /* size 0x88 */

Unk88 *func_002804C0(Unk88 *dst, Unk88 *src)
{
    *dst = *src;
    return dst;
}

}

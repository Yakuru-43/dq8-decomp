// range: 0x2805B0 0x2806A0
// best attempt, score 4 reorder-only; NOT a match, do not put in src/ as is
#include "common.h"

typedef struct Unk88 {
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
} Unk88; /* size 0x88 */

Unk88 *func_002805B0(Unk88 *dst, Unk88 *src)
{
    s32 *ts;
    s32 *td;
    s32 n;
    s32 *ts2;
    s32 *td2;
    s32 n2;

    ts = src->field_40;
    td = dst->field_40;
    n = 4;
    dst->field_00 = src->field_00;
    dst->field_04 = src->field_04;
    dst->field_08 = src->field_08;
    dst->field_0C = src->field_0C;
    dst->field_10 = src->field_10;
    dst->field_14 = src->field_14;
    dst->field_18 = src->field_18;
    dst->field_1C = src->field_1C;
    dst->field_20 = src->field_20;
    dst->field_24 = src->field_24;
    dst->field_28 = src->field_28;
    dst->field_2C = src->field_2C;
    dst->field_30 = src->field_30;
    dst->field_34 = src->field_34;
    dst->field_38 = src->field_38;
    dst->field_3C = src->field_3C;
    do {
        s32 a;
        s32 b;
        a = ts[0];
        b = ts[1];
        td[1] = b;
        td[0] = a;
        ts += 2;
        td += 2;
    } while (--n > 0);
    ts2 = src->field_60;
    td2 = dst->field_60;
    n2 = 4;
    do {
        s32 c;
        s32 d;
        c = ts2[0];
        d = ts2[1];
        td2[1] = d;
        td2[0] = c;
        ts2 += 2;
        td2 += 2;
    } while (--n2 > 0);
    dst->field_80 = src->field_80;
    dst->field_84 = src->field_84;
    return dst;
}

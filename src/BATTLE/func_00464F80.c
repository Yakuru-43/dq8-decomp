// range: 0x464F80 0x4650B0
#include "common.h"

typedef struct Sched464F80 {
    /* 0x00 */ s32 field_00;
    /* 0x04 */ s32 field_04;
    /* 0x08 */ char *field_08;
    /* 0x0C */ char *field_0C;
    /* 0x10 */ char *field_10;
    /* 0x14 */ char *field_14;
    /* 0x18 */ u8 pad_18[0x08];
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    /* 0x3C */ s32 field_3C;
    /* 0x40 */ u8 pad_40[0x18];
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    /* 0x60 */ u8 pad_60[0x04];
    /* 0x64 */ s32 field_64;
    /* 0x68 */ u8 pad_68[0x10];
    /* 0x78 */ s32 field_78;
    /* 0x7C */ s32 field_7C;
    /* 0x80 */ s32 field_80;
    /* 0x84 */ s32 field_84;
    /* 0x88 */ s32 field_88;
    /* 0x8C */ s32 field_8C;
    /* 0x90 */ s32 field_90;
    /* 0x94 */ s32 field_94;
    /* 0x98 */ s32 field_98;
    /* 0x9C */ s32 field_9C;
} Sched464F80; /* size 0xA0 */

extern char *func_14E130(void *, s32);

void func_00464F80(Sched464F80 *out, void *pool, s32 count, s32 rows) {
    s32 bytes1;
    s32 bytes2;
    s32 last;
    s32 wide;

    out->field_04 = 0;
    wide = rows + 2;
    out->field_00 = 0;
    bytes2 = count * wide * 16;
    bytes1 = count * 16;
    out->field_08 = func_14E130(pool, (bytes1 >> 4) + 1);
    out->field_0C = func_14E130(pool, (bytes1 >> 4) + 1);
    out->field_10 = func_14E130(pool, (bytes2 >> 4) + 1);
    out->field_14 = func_14E130(pool, (bytes2 >> 4) + 1);
    out->field_20 = 0x60;
    out->field_24 = 0x40;
    out->field_28 = 0x30;
    out->field_2C = 0x80;
    out->field_30 = 0x40;
    out->field_34 = 0x30;
    out->field_38 = 0x20;
    out->field_3C = 0x40;
    out->field_64 = 0;
    out->field_78 = count;
    out->field_58 = rows;
    out->field_5C = 0;
    out->field_7C = 0;
    last = count - 1;
    out->field_80 = last;
    out->field_84 = last;
    out->field_88 = 0;
    out->field_94 = 0;
    out->field_98 = 0;
    out->field_90 = 0;
    out->field_8C = 0x20;
}

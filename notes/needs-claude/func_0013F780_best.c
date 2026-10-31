// range: 0x13F780 0x13F980
// best attempt 2026-10-27 factory-1, CLASS structural score=12 (500 vs 500 B)
// (9 of the 12 "*" lines are unresolved-jal relocations - ignore them;
//  the real diff is the 7 words +0x150..+0x1A0 of the 0x71 RMW block.)
#include "common.h"

typedef struct {
    /* 00 */ u8 low : 3;
    /* 03 */ u8 bit3 : 1;
    /* 04 */ u8 bit4 : 1;
    /* 05 */ u8 bit5 : 1;
    /* 06 */ u8 bit6 : 1;
    /* 07 */ u8 bit7 : 1;
} Flags70;

typedef struct {
    /* 00 */ u8 bit0 : 1;
    /* 01 */ u8 bit1 : 1;
    /* 02 */ u8 rest : 6;
} Flags71;

typedef struct {
    /* 00 */ s32 mode;
    /* 04 */ s32 f04;
    /* 08 */ char pad08[0x10 - 0x08];
    /* 10 */ char buf[0x60];        /* streambuf sub-object */
    /* 70 */ Flags70 flags;
    /* 71 */ Flags71 flags71;
    /* 72 */ char pad72[0xE0 - 0x72];
    /* E0 */ s32 e0;
    /* E4 */ s32 e4;
    /* E8 */ s32 e8;
    /* EC */ char padEC[0x11C - 0xEC];
    /* 11C */ s32 posMode;
    /* 120 */ s32 x120;
    /* 124 */ s32 x124;
    /* 128 */ s32 x128;
    /* 12C */ s32 x12C;
    /* 130 */ s32 x130;
    /* 134 */ s32 x134;
} Stream;

typedef struct {
    /* 00 */ char pad00[0x04];
    /* 04 */ s32 x04;
    /* 08 */ s32 x08;
    /* 0C */ s32 x0C;
    /* 10 */ s32 x10;
} Source;

void func_0015BF80(void *);
void func_00157DE0(void *);
void func_00158140(Source *, s64 *);
void func_00157860(void *, void *);
void func_00157B30(void *, s32, s32);
void func_00157A40(void *, s32);
void func_00157990(void *, s32);
void func_00157930(void *, s32);
void func_001578D0(void *, s32);

/* Init the stream object: build the node at +0x10 and the sub-object at
 * +0x78, latch the extents from the source record, pick the position mode
 * and raise the ready flags. */
void func_0013F780(Stream *o, s32 mode, Source *st) {
    u8 b;

    o->mode = mode;
    o->f04 = 0;
    o->e8 = 1;
    func_0015BF80((char *)o + 0x78);
    func_00157DE0(o->buf);
    func_00158140(st, (s64 *)((char *)o + 0x40));
    func_00157860(o->buf, (char *)st + 0x80);
    o->x128 = st->x0C << 4;
    o->x12C = st->x10 << 4;
    o->x130 = st->x04 << 4;
    o->x134 = st->x08 << 4;
    o->posMode = 0;
    if (o->posMode == 1) {
        o->x124 = 0;
        o->x120 = 0;
    } else if (o->posMode == 2) {
        o->x120 = o->x128;
        o->x124 = o->x12C;
    } else {
        o->x120 = o->x128 - o->x130 / 2;
        o->x124 = o->x12C - o->x134 / 2;
    }
    b = M2C_FIELD(o, u8 *, 0x70);
    o->flags.bit6 = 0;
    func_00157B30(o->buf, 1, b);
    func_00157A40(o->buf, 0);
    func_00157990(o->buf, 2);
    o->e4 = 1;
    func_00157930(o->buf, o->e4);
    func_001578D0(o->buf, 0);
    o->flags.bit4 = 0;
    o->flags71.bit1 = 0;
    o->e0 = 1;
    o->flags.bit3 = 0;
    o->flags.bit7 = 0;
    o->flags.bit5 = 0;
}

// range: 0x13FA20 0x13FB30
// best attempt 2026-10-26 factory-1 (-O3), CLASS structural score=58 (252 vs 260 B)
#include "common.h"

extern "C" {

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
    /* 01 */ u8 rest : 7;
} Flags71;

typedef struct {
    /* 00 */ char pad00[0x10];
    /* 10 */ char buf[0x60];        /* streambuf sub-object */
    /* 70 */ Flags70 flags;
    /* 71 */ Flags71 flags71;
    /* 72 */ char pad72[0xE0 - 0x72];
    /* E0 */ s32 e0;
    /* E4 */ s32 e4;
} Stream;

void func_00157B30(void *, s32, s32);
void func_00157A40(void *, s32);
void func_00157990(void *, s32);
void func_00157930(void *, s32);
void func_001578D0(void *, s32);

/* Restart the stream: reopen the buffer, rewind it, raise the ready flags. */
void func_0013FA20(Stream *o) {
    u8 b;

    b = M2C_FIELD(o, u8 *, 0x70);
    o->flags.bit6 = 1;
    func_00157B30(o->buf, 1, b);
    func_00157A40(o->buf, 0);
    func_00157990(o->buf, 2);
    M2C_FIELD(o, s32 *, 0xE4) = 1;
    func_00157930(o->buf, M2C_FIELD(o, s32 *, 0xE4));
    func_001578D0(o->buf, 0);
    o->flags.bit4 = 1;
    o->flags71.bit0 = 1;
    o->e0 = 1;
    o->flags.bit3 = 1;
    o->flags.bit7 = 1;
    o->flags.bit5 = 1;
}

}

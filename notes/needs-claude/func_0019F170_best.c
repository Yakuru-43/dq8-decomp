// range: 0x19F170 0x19F330
// flags: -flag divbyzerocheck
// (the original guards the divides with bnez + break 0, 7)
#include "common.h"

s32 WaitSema(s32);
s32 SignalSema(s32);

extern s32 D_1000B410 __attribute__((section(".data")));
extern u32 D_10002020 __attribute__((section(".data")));

typedef struct {
    /* 0x00 */ u64 q0;
    /* 0x08 */ u64 q1;
    /* 0x10 */ s32 m10;
    /* 0x14 */ s32 m14;
} PoolEntry;

typedef struct {
    /* 0x00 */ s32 m00;
    /* 0x04 */ s32 pad04;
    /* 0x08 */ s32 m08;
    /* 0x0C */ u8 pad0C[0x2C];
    /* 0x38 */ u32 m38;
    /* 0x3C */ u8 pad3C[4];
    /* 0x40 */ s32 sema;
    /* 0x44 */ u8 pad44[0xC];
    /* 0x50 */ PoolEntry *entries;
    /* 0x54 */ s32 m54;
    /* 0x58 */ s32 count;
    /* 0x5C */ s32 m5C;
} Pool;

s32 func_0019F170(Pool *o, s64 *out) {
    s32 base;
    s32 flags;
    u32 cfg;
    s32 stride;
    s32 found;
    s32 rem;
    s32 span;
    s32 count;
    s32 i;
    s32 mod;
    s32 t;
    s32 dec;

    found = 0;
    base = D_1000B410;
    flags = (s32)(o->m38 & 0x7F);
    cfg = D_10002020;
    stride = WaitSema(o->sema) << 11;
    out[0] = -1;
    out[1] = -1;
    rem = (s32)((u32)(stride + (base - (((cfg >> 8) & 0xF) + ((cfg >> 16) & 3)) * 16) +
                   (flags >> 3)) - (u32)o->m00) %
            (u32)stride;
    count = o->count;
    span = o->m5C - count;
    rem = rem + stride;
    for (i = 0; i < count && found == 0; i++) {
        t = o->m54;
        mod = (i + t + span) % t;
        if ((rem - o->entries[mod].m10) % stride < o->entries[mod].m14) {
            out[0] = o->entries[mod].q0;
            out[1] = o->entries[mod].q1;
            o->entries[mod].q0 = -1;
            o->entries[mod].q1 = -1;
            dec = o->count;
            found = 1;
            if (dec > 0) {
                dec = found;
            }
            o->count = o->count - dec;
        }
    }
    SignalSema(o->sema);
    return 1;
}

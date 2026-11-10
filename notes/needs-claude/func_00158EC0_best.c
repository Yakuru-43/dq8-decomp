// range: 0x158EC0 0x159150
// best attempt, 648 B vs 656 B, CLASS structural score=162 — see func_00158EC0.md
#include "common.h"

/* Builds a DMA packet: a 0x70-byte header, an optional tag record, then
 * `count` 0x30-byte unpack records. Returns the number of words written. */
s32 func_00158EC0(s32 *pkt, s32 arg1, s32 arg2, s32 arg3, s32 cursor, s32 count,
                  s32 arg6, s32 arg7, s32 arg8, u32 arg9) {
    s32 *base;
    s32 *p;
    s64 pack;
    s32 n;
    s32 q;

    base = pkt;
    pack = (s64)arg1 | (s64)(arg3 << 16) | (s64)(arg2 << 24);
    pkt[0] = 0x10000006;
    pkt[1] = 0;
    pkt[2] = 0;
    pkt[3] = 0x50000006;
    pkt[4] = 5;
    pkt[5] = 0x10000000;
    pkt[6] = 0xE;
    pkt[7] = 0;
    pkt[8] = 0;
    pkt[9] = 0;
    pkt[10] = 0x3F;
    pkt[11] = 0;
    pkt[12] = (s32)pack;
    pkt[13] = (s32)(pack >> 32);
    pkt[14] = 0x50;
    pkt[15] = 0;
    pack = (s64)arg6 | (s64)(arg7 << 16);
    pkt[16] = (s32)pack;
    pkt[17] = (s32)(pack >> 32);
    pkt[18] = 0x51;
    pkt[19] = 0;
    pack = (s64)arg8 | (s64)((u32)arg9 & 0xFFFFFFFF);
    pkt[20] = (s32)pack;
    pkt[21] = (s32)(pack >> 32);
    pkt[22] = 0x52;
    pkt[23] = 0;
    pkt[24] = 0;
    pkt[25] = 0;
    pkt[26] = 0x53;
    pkt[27] = 0;
    p = pkt + 0x1C;
    n = cursor & 0x7F;
    if (n != 0x10) {
        q = (0x90 - n) / 16;
        p[0] = 0x10000001;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0x50000001;
        p[4] = q | 0x8000;
        p[5] = 0x08000000;
        p[6] = 0;
        p[7] = 0;
        p[8] = q | 0x30000000;
        p[9] = cursor;
        p[10] = 0;
        p[11] = q | 0x50000000;
        count -= q;
        cursor += q << 4;
        p += 0xC;
    }
    while (count > 0) {
        q = (count < 0x7FF0) ? count : 0x7FF0;
        p[0] = 0x10000001;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0x50000001;
        p[4] = q | 0x8000;
        p[5] = 0x08000000;
        p[6] = 0;
        p[7] = 0;
        p[8] = q | 0x30000000;
        p[9] = cursor;
        p[10] = 0;
        p[11] = q | 0x50000001;
        count -= 0x7FF0;
        cursor += q << 4;
        p += 0xC;
    }
    return p - base;
}

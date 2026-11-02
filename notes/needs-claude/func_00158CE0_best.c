// best attempt 2026-11-02 Qwen factory-1 — CLASS structural score=119
// (92 words differ, 368 vs 476 bytes).
// range: 0x158CE0 0x158EC0
#include "common.h"

/* Build a DMA-style packet list at dst: one 0x70-byte header, then one
 * 0x30-byte packet per 0x7FF0 chunk of count(t1).  Returns words written. */
s32 func_00158CE0(u32 *dst, u32 a1, u32 a2, u32 a3, u32 base, s32 count,
                  s32 arg6, s32 arg7, u32 lo, u32 hi) {
    u32 *cur;
    u32 comb;
    s32 n;
    u64 packed;

    comb = (u32)a1 | ((u32)a3 << 16) | ((u32)a2 << 24);
    cur = dst;
    cur[0] = 0x10000006;
    cur[1] = 0;
    cur[2] = 0;
    cur[3] = 0;
    cur[4] = 5;
    cur[5] = 0x10000000;
    cur[6] = 0xE;
    cur[7] = 0;
    cur[8] = 0;
    cur[9] = 0;
    cur[10] = 0x3F;
    cur[11] = 0;
    cur[12] = (s32)(comb & 0xFFFF0000);
    cur[13] = (s32)((u32)comb & 0xFFFF0000);
    cur[14] = 0x50;
    cur[15] = 0;
    cur[16] = (s32)(comb >> 16);
    cur[17] = (s32)(a2 & 0xFFFF0000);
    cur[18] = 0x51;
    packed = (u64)lo | ((u64)hi << 32);
    cur[19] = 0;
    cur[20] = (s32)(packed & 0xFFFF0000);
    cur[21] = (s32)(((u64)packed >> 32) & 0xFFFF0000u);
    cur[22] = 0x52;
    cur[23] = 0;
    cur[24] = 0;
    cur[25] = 0;
    cur[26] = 0x53;
    cur[27] = 0;
    cur = (u32 *)((u8 *)cur + 0x70);
    while (count > 0) {
        n = count;
        if (count >= 0x7FF0) {
            n = 0x7FF0;
        }
        cur[0] = 0x10000001;
        cur[1] = 0;
        cur[2] = 0;
        cur[3] = 0;
        cur[4] = n | 0x8000;
        cur[5] = 0x800;
        cur[6] = 0;
        cur[7] = 0;
        cur[8] = n | 0x3000;
        cur[9] = base;
        cur[10] = 0;
        cur[11] = 0;
        base += n * 16;
        cur = (u32 *)((u8 *)cur + 0x30);
        count -= 0x7FF0;
    }
    return (s32)((u8 *)cur - (u8 *)dst) / 4;
}

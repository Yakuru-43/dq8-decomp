/* Best attempt 2026-11-03 (factory-2): CLASS structural score=130, 516/544
 * bytes. Delay slots: mine fills (bgtzl, beql), original never does. */
// range: 0x21C490 0x21C6B0
#include "common.h"

s32 func_0021C490(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4, u16 *arg5) {
    u32 end;
    s32 base;
    s32 bytes;
    s32 words;
    s32 idx;
    f32 *fdst;
    f32 *fsrc;
    u16 *wdst;
    u16 *wsrc;
    u8 *dst;
    u8 *src;

    end = (u32)arg0;
    switch (arg4) {
    case 0x20:
        *(u32 *)arg0 = 0x68000000 | ((arg1 | 0x8000) | (arg2 << 16));
        base = (s32)end + 4;
        fdst = (f32 *)base;
        while (arg2 > 0) {
            idx = *arg5;
            arg2 = arg2 - 1;
            arg5 = arg5 + 1;
            fsrc = (f32 *)(arg3 + idx * 12);
            fdst[0] = fsrc[0];
            fdst[1] = fsrc[1];
            fdst[2] = fsrc[2];
            fdst = fdst + 3;
        }
        end = (u32)(base + (((s32)fdst - base) / 4) * 4);
        break;
    case 0x10:
        *(u32 *)arg0 = 0x69000000 | ((arg1 | 0x8000) | (arg2 << 16));
        base = (s32)end + 4;
        wdst = (u16 *)base;
        bytes = arg2 * 6;
        words = bytes / 4;
        if (bytes % 4 != 0) {
            words = words + 1;
        }
        while (arg2 > 0) {
            idx = *arg5;
            arg2 = arg2 - 1;
            arg5 = arg5 + 1;
            wsrc = (u16 *)(arg3 + idx * 6);
            wdst[0] = wsrc[0];
            wdst[1] = wsrc[1];
            wdst[2] = wsrc[2];
            wdst = wdst + 3;
        }
        end = (u32)(base + words * 4);
        break;
    case 8:
        *(u32 *)arg0 = 0x6A000000 | ((arg1 | 0x8000) | (arg2 << 16));
        base = (s32)end + 4;
        dst = (u8 *)base;
        bytes = arg2 * 3;
        words = bytes / 4;
        if (bytes % 4 != 0) {
            words = words + 1;
        }
        while (arg2 > 0) {
            idx = *arg5;
            arg2 = arg2 - 1;
            arg5 = arg5 + 1;
            src = arg3 + idx * 3;
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst = dst + 3;
        }
        end = (u32)(base + words * 4);
        break;
    }
    return ((s32)end - arg0) / 4;
}

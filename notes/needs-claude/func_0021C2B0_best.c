// best attempt, 2026-11-01 factory-2 — CLASS structural score=113 (91 words differ, 388 vs 476)
// range: 0x21C2B0 0x21C490
#include "common.h"

typedef struct {
    /* 0x0 */ f32 u;
    /* 0x4 */ f32 v;
} Pair2;

s32 func_0021C2B0(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4, u16 *arg5) {
    u32 end;
    u32 base;
    Pair2 *dst;
    u32 *dstw;
    u16 *dsth;
    s32 n4;
    s32 idx;

    end = (u32)arg0;
    switch (arg4) {
    case 0x20:
        *(u32 *)arg0 = 0x64000000 | ((arg1 | 0xC000) | (arg2 << 16));
        base = (u32)((s32)end + 4);
        dst = (Pair2 *)base;
        while (arg2 > 0) {
            idx = *arg5;
            arg2 = arg2 - 1;
            arg5 = arg5 + 1;
            *dst = *(Pair2 *)((char *)arg3 + idx * 8);
            dst = dst + 1;
        }
        end = base + ((((s32)dst - (s32)base) / 4) * 4);
        break;
    case 0x10:
        end = end + 4;
        dstw = (u32 *)end;
        n4 = (arg2 * 4 + 3) / 4;
        *(u32 *)arg0 = 0x65000000 | ((arg1 | 0xC000) | (arg2 << 16));
        while (arg2 > 0) {
            idx = *arg5;
            arg2 = arg2 - 1;
            arg5 = arg5 + 1;
            *dstw = *(s32 *)((char *)arg3 + idx * 4);
            dstw = dstw + 1;
        }
        end = end + n4 * 4;
        break;
    case 8:
        end = end + 4;
        dsth = (u16 *)end;
        n4 = (arg2 * 2 + 3) / 4;
        *(u32 *)arg0 = 0x66000000 | ((arg1 | 0xC000) | (arg2 << 16));
        while (arg2 > 0) {
            idx = *arg5;
            arg2 = arg2 - 1;
            arg5 = arg5 + 1;
            *dsth = *(u16 *)((char *)arg3 + idx * 2);
            dsth = dsth + 1;
        }
        end = end + n4 * 4;
        break;
    }
    return ((s32)end - arg0) / 4;
}

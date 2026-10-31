// range: 0x21C6B0 0x21C760
#include "common.h"

s32 func_0021C6B0(s32 arg0, s32 arg1, s32 arg2, u32 *arg3, s32 arg4, u16 *arg5) {
    u32 end;
    s32 base;
    u32 *dst;
    s32 idx;

    end = (u32)arg0;
    switch (arg4) {
    case 0x20:
    case 0x10:
        break;
    case 8:
        *(u32 *)arg0 = 0x6E000000 | ((arg1 | 0xC000) | (arg2 << 16));
        base = (s32)end + 4;
        dst = (u32 *)base;
        while (arg2 > 0) {
            idx = *arg5;
            arg2 = arg2 - 1;
            arg5 = arg5 + 1;
            *dst = arg3[idx];
            dst = dst + 1;
        }
        end = (u32)(base + (((s32)dst - base) / 4) * 4);
        break;
    }
    return ((s32)end - arg0) / 4;
}

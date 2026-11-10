// range: 0x157FB0 0x158130
// best attempt, CLASS structural score=91 (89 words differ, 376 vs 384 bytes)
#include "common.h"

void func_00157FB0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s64 arg5) {
    s32 t6 = arg2;
    s32 t2 = arg2 & 0x3F;
    s32 v1;
    s32 q;

    M2C_FIELD(arg0, s32 *, 4) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = arg3;
    M2C_FIELD(arg0, s32 *, 0x30) = arg4;
    if (arg2 < 0) {
        if (t2 != 0) {
            t2 = t2 - 0x40;
        }
    }
    if (t2 != 0) {
        v1 = 0x40 - t2;
        t6 = t6 + v1;
    }
    M2C_FIELD(arg0, u16 *, 0x80) = (M2C_FIELD(arg0, u16 *, 0x80) & ~0x1FF) | (arg1 & 0x1FF);
    q = t6 / 64;
    M2C_FIELD(arg0, u8 *, 0x82) = (M2C_FIELD(arg0, u8 *, 0x82) & ~0x3F) | (q & 0x3F);
    M2C_FIELD(arg0, u8 *, 0x83) = (M2C_FIELD(arg0, u8 *, 0x83) & ~0x3F) | (arg4 & 0x3F);
    M2C_FIELD(arg0, u64 *, 0x80) = (M2C_FIELD(arg0, u64 *, 0x80) & 0xFFFFFFFF) | ((u64)(s32)arg5 << 32);
    M2C_FIELD(arg0, s16 *, 0xA0) = (M2C_FIELD(arg0, s32 *, 0xC) - arg2 / 2) << 4;
    M2C_FIELD(arg0, s16 *, 0xA4) = (M2C_FIELD(arg0, s32 *, 0x10) - arg3 / 2) << 4;
    M2C_FIELD(arg0, u16 *, 0xB0) = (M2C_FIELD(arg0, u16 *, 0xB0) & ~0x7FF) | 0x7FF;
    M2C_FIELD(arg0, u16 *, 0xB2) = (M2C_FIELD(arg0, u16 *, 0xB2) & ~0x7FF) | ((arg2 - 1) & 0x7FF);
    M2C_FIELD(arg0, u16 *, 0xB4) = (M2C_FIELD(arg0, u16 *, 0xB4) & ~0x7FF) | 0x7FF;
    M2C_FIELD(arg0, u16 *, 0xB6) = (M2C_FIELD(arg0, u16 *, 0xB6) & ~0x7FF) | ((arg3 - 1) & 0x7FF);
    M2C_FIELD(arg0, u8 *, 0xC0) = (M2C_FIELD(arg0, u8 *, 0xC0) & ~1) | 1;
}

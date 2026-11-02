// range: 0x3194E0 0x319660
#include "common.h"

struct Byte3 {
    u8 b7, b8, b9;
};

struct Byte2 {
    u8 bE, bF;
};

struct Quad {
    f32 v0, v1, v2, v3;
};

struct Entry50 {
    Entry50() {}

    u8 f00, f01, f02, f03, f04, f05, f06;       /* 0x000 */
    Byte3 f07;                                  /* 0x007 */
    u8 f0A, f0B;                                /* 0x00A */
    u16 f0C;                                    /* 0x00C */
    u8 f0E, f0F, f10, f11, f12, f13, f14;       /* 0x00E */
    s8 f15[11];                                 /* 0x015 */
    s32 f20, f24;                               /* 0x020 */
    s8 f28[8];                                  /* 0x028 */
    Quad f30;                                   /* 0x030 */
    s16 f40[6];                                 /* 0x040 */
    u8 f4C, f4D;                                /* 0x04C */
    Byte2 f4E;                                  /* 0x04E */
};

extern "C" Entry50 *func_003194E0(Entry50 *dst, Entry50 *src) {
    *dst = *src;
    return dst;
}

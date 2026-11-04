// range: 0x35E6D0 0x35E860
// Copies a 0x80-byte template (D_003D3A80 in the ctor below) into a
// sub-object at +0x60 of the big record func_0035E5E0 builds.
#include "common.h"

struct Vec2 {
    f32 x, y;
};

struct Pair16 {
    s16 lo, hi;
};

struct Entry {
    Entry() {}

    s16 f00;                     /* 0x000 */
    Vec2 f04;                    /* 0x004 */
    Pair16 f0C;                  /* 0x00C */
    Vec2 f10;                    /* 0x010 */
    Pair16 f18;                  /* 0x018 */
    Vec2 f1C;                    /* 0x01C */
    Pair16 f24;                  /* 0x024 */
    Pair16 f28;                  /* 0x028 */
    Vec2 f2C;                    /* 0x02C */
    Vec2 f34;                    /* 0x034 */
    s32 f3C;                     /* 0x03C */
    u8 f40, f41;                 /* 0x040 */
    s16 f42, f44, f46;           /* 0x042 */
    s16 f48, f4A, f4C;           /* 0x048 */
    s16 f4E[5];                  /* 0x04E */
    s8 f58[6];                   /* 0x058 */
    Vec2 f60;                    /* 0x060 */
    s16 f68, f6A, f6C;           /* 0x068 */
    s32 f70, f74, f78, f7C;      /* 0x070 */
};

extern "C" Entry *func_0035E6D0(Entry *dst, const Entry *src) {
    *dst = *src;
    return dst;
}

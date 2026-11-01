// range: 0x00140DD0 0x00140F40
#include "common.h"

s32 func_00140DD0(s32 x, s32 y, s32 fmt) {
    s32 bpp = 0;
    s32 area;
    s32 r;

    switch (fmt) {
    case 0:
    case 1:
    case 0x30:
    case 0x31:
        bpp = 0x20;
        r = x % 64;
        if (r != 0) {
            x += 0x20 - r;
        }
        r = y % 32;
        if (r != 0) {
            y += 0x20 - r;
        }
        break;
    case 2:
    case 0xA:
    case 0x32:
    case 0x3A:
        bpp = 0x10;
        r = x % 64;
        if (r != 0) {
            x += 0x20 - r;
        }
        r = y % 64;
        if (r != 0) {
            y += 0x40 - r;
        }
        break;
    }

    area = x * y;
    bpp = bpp * area;
    area = bpp / 8;
    bpp = area / 256;
    r = bpp % 32;
    if (r != 0) {
        bpp += 0x20 - r;
    }
    return bpp;
}

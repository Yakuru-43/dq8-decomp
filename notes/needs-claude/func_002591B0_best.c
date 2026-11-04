// range: 0x2591B0 0x259320
// best draft for func_002591B0 (score 12, see func_002591B0.md)
#include "common.h"

extern s32 func_0019A290(void);

s32 func_002591B0(s32 id) {
    s32 x = id;
    s32 ret;

    if (func_0019A290() == 2) {
        x = -0x2710;
    }
    ret = 0;
    if (x == -0x2D3) {
        ret = 0;
    }
    if (x == -0x399) {
        ret = 1;
    }
    if (x == -0x39A) {
        ret = 1;
    }
    if (x == -0x58E) {
        ret = 0x12;
    }
    if (x == -0x58D) {
        ret = 0x12;
    }
    if (x == -0x4B6) {
        ret = 3;
    }
    if (x == -0x25E) {
        ret = 4;
    }
    if (x == -0x6AA) {
        ret = 5;
    }
    if (x == -0x389) {
        ret = 6;
    }
    if (x == -0x7DB) {
        ret = 7;
    }
    if (x == -0x334 || x == -0x398) {
        ret = 0x1A;
    }
    if ((u32)(x + 0x784) < 2) {
        ret = 0x25;
    }
    if (x == -0x2710) {
        ret = 8;
    }
    if ((u32)(x + 0x518) < 2) {
        ret = 0x21;
    }
    if (x == -0x458) {
        ret = 0x3E;
    }
    if (x == -0x3F9) {
        ret = 0x1F;
    }
    if (x == -0x192) {
        ret = 0x7C;
    }
    if (x == -0x3F1) {
        return 0x7D;
    }
    return ret;
}

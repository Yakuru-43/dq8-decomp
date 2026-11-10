// best C for func_002172B0, 2026-11-03 factory-2 (not matched; kept out of src/)
// range: 0x2172B0 0x217560
#include "common.h"

struct SectorPos {
    f32 x;
    f32 pad0;
    f32 y;
    f32 pad1;
};

extern u8 D_003DFD10[];
extern f32 D_003DF4AC;
extern f32 D_003DF4B0;
extern char *D_003E0908;

void func_002172B0(struct SectorPos *pos, s8 *out, s32 *arg2, s32 arg3) {
    f32 x = pos->x + 56000.0f + 2000.0f;
    f32 y = pos->y + 39936.0f + 2000.0f;
    s32 ix = (s32)(x / 16000.0f);
    s32 iy = (s32)(y / 16000.0f);
    s32 i;

    if (x - (f32)ix * 16000.0f < 8000.0f) {
        ix -= 1;
    }
    if (y - (f32)iy * 16000.0f < 8000.0f) {
        iy -= 1;
    }
    for (i = 0; i < 4; i++) {
        s8 *p = out + i * 32;
        p[0] = (s8)(iy + D_003DFD10[i * 2 + 1] + 0x61);
        p[1] = 0x30;
        p[2] = (s8)(ix + D_003DFD10[i * 2] + 0x30);
        p[3] = 0;
        if (p[0] < 0x67) {
            p[0] = 0x68;
        }
        if (p[2] < 0x30 || p[2] >= 0x37) {
            p[2] = 0x38;
        }
    }
    {
        s32 v = arg3 ? 0x200 : 0x180;
        s32 half = v / 2;
        f32 ax = x * D_003DF4AC;
        f32 ay = y * D_003DF4B0;

        arg2[0] = (s32)((f32)ix * 16000.0f * D_003DF4AC);
        arg2[1] = (s32)(D_003DF4B0 * (f32)iy * 16000.0f);
        arg2[0] -= (s32)ax;
        arg2[1] -= (s32)ay;
        *(f32 *)(D_003E0908 + 0x460) -= (f32)(s32)ax;
        *(f32 *)(D_003E0908 + 0x464) -= (f32)(s32)ay;
        arg2[0] += 0x100;
        arg2[1] += 0xE0;
        *(f32 *)(D_003E0908 + 0x460) += (f32)half;
        *(f32 *)(D_003E0908 + 0x464) += (f32)half;
    }
}

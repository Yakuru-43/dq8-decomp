// best attempt 2026-11-04 factory-1 — compiles, try_match CLASS structural score=150
// (604 vs 660 bytes; the 56-byte gap = the 3 inline memset loops that came out as
//  jal memset). See notes/needs-claude/func_0019A810.md for the analysis.
// range: 0x19A810 0x19AAB0
#include "common.h"

void *memset(void *, s32, s32);
char *func_0015F490(void);
void func_0013F240(char *, s32, s32, s32, s32);
void func_0013EFF0(char *, u128 *);
void func_0013F0E0(char *);
s32 func_001453A0(char *);
s32 func_00145390(char *);
s32 func_00145440(char *);
extern f32 D_003DFCA8;
extern f32 D_003DFCAC;

union Scale {
    f32 f[2];
    s32 w[2];
};

void func_0019A810(char *writer, s32 x, s32 y, s32 mode) {
    union Scale scale;
    s32 pkt2[4];
    s32 pkt1[4];
    s32 pkt0[4];
    char *ctx;
    s32 n16;
    s32 xv;
    s32 yv;
    s32 t;
    s32 v;
    s32 i;

    ctx = func_0015F490();
    func_0013F240(writer, 4, 0x43, 0, 2);
    memset(pkt2, 0, 16);
    pkt2[0] = func_001453A0(ctx) << 4;
    pkt2[1] = func_00145390(ctx) << 4;
    n16 = func_00145440(ctx) / 16;
    memset(pkt1, 0, 16);
    memset(pkt0, 0, 16);
    scale.f[0] = D_003DFCA8;
    scale.f[1] = D_003DFCAC;
    xv = x << 4;
    yv = y << 4;
    i = 0;
    do {
        if (mode == 0) {
            v = xv;
        } else {
            v = (scale.w[i % 2] + x) << 4;
        }
        if (v < 0) {
            pkt0[0] = 0;
        } else {
            pkt0[0] = v;
        }
        t = (i * n16) << 4;
        pkt0[1] = t;
        func_0013EFF0(writer, (u128 *)pkt0);
        pkt1[0] = pkt0[0] + pkt2[0];
        pkt1[1] = pkt0[1] + pkt2[1];
        func_0013EFF0(writer, (u128 *)pkt1);
        if (mode != 0) {
            pkt0[0] = yv;
        } else {
            pkt0[0] = (scale.w[i % 2] + y) << 4;
        }
        if (pkt0[0] < 0) {
            pkt0[0] = 0;
        }
        pkt0[1] = t;
        func_0013EFF0(writer, (u128 *)pkt0);
        pkt1[1] = pkt0[1] + pkt2[1];
        pkt1[0] = pkt0[0] + pkt2[0];
        func_0013EFF0(writer, (u128 *)pkt1);
        i = i + 1;
    } while (i < 17);
    func_0013F0E0(writer);
}

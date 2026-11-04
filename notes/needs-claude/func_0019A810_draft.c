// range: 0x19A810 0x19AAB0
#include "common.h"

extern char *func_0015F490(void);
extern void func_0013F240(char *, s32, s32, s32, s32);
extern s32 func_001453A0(char *);
extern s32 func_00145390(char *);
extern s32 func_00145440(char *);
extern void func_0013EFF0();
extern void func_0013F0E0(char *);
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
    s32 n16;
    char *ctx;
    s32 i;
    s32 t;
    s32 v;

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
    for (i = 0; i < 17; i++) {
        if (mode != 0) {
            t = (i < 0) ? (i % 2) : (x << 4);
            v = (scale.w[t] + x) << 4;
        } else {
            v = x << 4;
        }
        pkt0[0] = v < 0 ? 0 : v;
        func_0013EFF0(writer, pkt0);
        pkt0[1] = (i * n16) << 4;
        pkt1[0] = pkt0[0] + pkt2[0];
        pkt1[1] = pkt0[1] + pkt2[1];
        func_0013EFF0(writer, pkt1, pkt0[0] + pkt2[0], pkt0[0]);
        if (mode == 0) {
            t = (i < 0) ? (i % 2) : (y << 4);
            v = (scale.w[t] + y) << 4;
        } else {
            v = y << 4;
        }
        pkt0[0] = v;
        if (pkt0[0] < 0) {
            pkt0[0] = 0;
        }
        pkt0[1] = (i * n16) << 4;
        func_0013EFF0(writer, pkt0);
        pkt1[0] = pkt0[0] + pkt2[0];
        pkt1[1] = pkt0[1] + pkt2[1];
        func_0013EFF0(writer, pkt1, pkt0[0] + pkt2[0], pkt0[0]);
    }
    func_0013F0E0(writer);
}

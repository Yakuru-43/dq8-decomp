// range: 0x30F550 0x30F700
#include "common.h"

struct Out {
    s32 f0;
    s32 f4;
    s32 f8;
    char padC[0x1E8 - 0xC];
    void *f1E8;
};

struct Rec {
    s64 f0;
    s64 f8;
};

struct Unit {
    char pad0[0x10];
    s16 f10;
    s16 f12;
    char pad14[0xE0 - 0x14];
    struct Rec recs[39];
    u8 f350;
};

extern f32 D_003DF390;
extern M2C_UNK D_003E1160;

extern void func_0029C600(void *arg0);
extern s32 func_00297090(void *arg0);
extern s32 func_002970A0(void *arg0);
extern s32 func_0030FE50(void *ai, s32 a, s32 b);
extern s32 func_0030FE30(void *arg0, void *arg1, s32 arg2);
extern s32 func_0030FEC0(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern s32 func_003103D0(void);
extern s32 func_00310390(void);
extern f32 func_00328110(M2C_UNK *arg0);
extern void func_0030ECD0(void *arg0, void *arg1);
extern void func_0030F360(void *arg0, void *arg1);

/* save the record block, roll a try at the vis target, restore: on success
 * the target id and the two halves go to out, on failure nothing does */
void func_0030F550(void *arg0, struct Out *out, struct Unit *ai) {
    struct Rec buf[42];
    struct Rec *src;
    struct Rec *dst;
    f32 f20;
    f32 ratio;
    s32 i;

    src = ai->recs;
    dst = buf;
    for (i = 42; i > 0; i = i - 1) {
        *dst = *src;
        dst = dst + 1;
        src = src + 1;
    }
    func_0029C600(out);
    if (ai->f350 == 2) {
        f20 = (f32) func_00297090(ai);
        ratio = f20 / (f32) func_002970A0(ai);
        if (ratio < 0.5f) {
            if (func_0030FE50(ai, (s32) out->f1E8, 1) == 0) {
                if (func_0030FE30(ai, out->f1E8, 1) == 0 ||
                        func_003103D0() >= func_00310390()) {
                    f20 = 0.0f;
                    if (ratio < D_003DF390) {
                        f20 = D_003DF390;
                    }
                    if (func_00328110(&D_003E1160) <= f20) {
                        if (func_0030FEC0(ai, 0x50, out->f1E8, 1) != 0) {
                            out->f0 = 0x50;
                        } else {
                            out->f0 = 0x4E;
                        }
                        out->f4 = ai->f10;
                        out->f8 = ai->f12;
                    }
                }
            }
        }
    }
    func_0030ECD0(ai->recs, buf);
    func_0030F360(arg0, out);
}

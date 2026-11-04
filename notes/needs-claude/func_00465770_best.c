// range: 0x465770 0x465A90
#include "common.h"

void func_10AB78(f32 *, f32 *, f32 *);
void func_10AB48(f32 *, f32 *, f32 *);

s32 func_00465770(f32 *out, f32 *pts, s32 count, s32 samples, s32 base, s32 limit) {
    f32 coeff[16];
    f32 ctrl[16];
    f32 mat[16];
    f32 pw[4];
    f32 res[4];
    s32 idx[4];
    f32 *p;
    f32 span;
    f32 step;
    f32 stop;
    f32 t;
    f32 tt;
    s32 seg;
    s32 made;
    s32 i;
    s32 j;
    s32 k;
    s32 v;

    if (count < 3) {
        return 0;
    }
    span = (f32)samples - 1.0f;
    made = 0;
    seg = 0;
    mat[0] = -0.25f / 0.5f;
    mat[1] = 1.5f;
    mat[2] = (-0.5f - 0.25f) / 0.5f;
    mat[3] = 0.5f;
    mat[4] = 1.0f;
    mat[5] = -1.25f / 0.5f;
    mat[6] = 2.0f;
    mat[7] = -0.5f;
    mat[8] = -0.25f / 0.5f;
    mat[9] = 0.0f;
    mat[10] = 0.5f;
    mat[11] = 0.0f;
    mat[12] = 0.0f;
    mat[13] = 1.0f;
    mat[14] = 0.0f;
    mat[15] = 0.0f;
    for (seg = 0; seg < count - 1; seg++) {
        if (0 < seg && seg < count - 2) {
            idx[0] = seg - 1;
            idx[1] = seg;
            idx[2] = seg + 1;
            idx[3] = seg + 2;
        } else {
            if (seg <= 0) {
                idx[0] = 0;
                idx[1] = 0;
                idx[2] = 1;
                idx[3] = 2;
            }
            if (seg >= count - 2) {
                idx[0] = seg - 1;
                idx[1] = seg;
                idx[2] = seg + 1;
                idx[3] = seg + 1;
            }
        }
        for (i = 0; i < 4; i++) {
            v = idx[i] + base;
            if (v < limit) {
                idx[i] = v;
            } else {
                idx[i] = v - limit;
            }
            if (idx[i] < 0) {
                idx[i] = idx[i] + limit;
            }
        }
        for (j = 0; j < 4; j++) {
            p = pts + idx[j] * 4;
            ctrl[j * 4] = p[0];
            ctrl[j * 4 + 1] = p[1];
            ctrl[j * 4 + 2] = p[2];
            ctrl[j * 4 + 3] = 0.0f;
        }
        func_10AB78(coeff, ctrl, mat);
        step = 1.0f / span;
        stop = 1.0f - step;
        for (t = 0.0f; t < stop; t += step) {
            tt = t * t;
            pw[0] = t * tt;
            pw[1] = tt;
            pw[2] = t;
            pw[3] = 1.0f;
            func_10AB48(res, coeff, pw);
            for (k = 0; k < 3; k++) {
                out[made * 4 + k] = res[k];
            }
            out[made * 4 + 3] = 1.0f;
            made++;
        }
    }
    return made;
}

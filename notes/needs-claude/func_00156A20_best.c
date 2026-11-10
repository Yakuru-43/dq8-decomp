// range: 0x156A20 0x156C40
// best draft at give-up, 532 vs 540 bytes, CLASS structural score=133
#include "common.h"

struct Curve {
    f32 q;       /* +0x00 */
    s32 type;    /* +0x04 */
    s16 *keys;   /* +0x08 */
    s32 base;    /* +0x0C */
    s32 count;   /* +0x10 */
    s32 i1;      /* +0x14 */
    s32 i2;      /* +0x18 */
    s32 k1;      /* +0x1C */
    s32 k2;      /* +0x20 */
};

extern f32 D_003DF3BC;
extern f32 D_003DF40C;

f32 func_00156A20(struct Curve *c) {
    s32 hi, lo, qi, d, c1, mid;
    s16 *keys;
    f32 q, t;

    hi = c->count;
    lo = 0;
    c->k1 = 0;
    c->k2 = 0;
    q = c->q;
    keys = c->keys;
    qi = (s32)q;
    if (keys != 0) {
        if (c->type != 16) {
            c->i2 = 0;
            c->i1 = 0;
            return 0.0f;
        }
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (qi < keys[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        c->i1 = lo - 1;
        c->i2 = lo;
        if (c->i2 == 0) {
            c->i1 = 0;
            return 0.0f;
        }
        hi = c->count;
        if (c->i2 >= hi) {
            c->i2 = c->i1;
            return 0.0f;
        }
        if (c->i1 >= hi) {
            c->i2 = hi - 1;
            c->i1 = hi - 1;
            return 0.0f;
        }
        c->k1 = keys[c->i1];
        c->k2 = keys[c->i2];
        t = (f32)(c->k2 - c->k1);
        if (t > 0.0f) {
            t = (q - (f32)c->k1) / t;
        }
    } else {
        d = qi - c->base;
        c->i1 = d;
        c1 = c->count - 1;
        if (c->i1 >= c1) {
            c->i2 = c1;
            c->i1 = c1;
            return 0.0f;
        }
        c->i2 = c->i1 + 1;
        if (c->i2 <= 0) {
            c->i1 = 0;
            return 0.0f;
        }
        if (c->i2 >= c->count) {
            c->i2 = c->i1;
            return 0.0f;
        }
        c->k1 = qi;
        c->k2 = qi + 1;
        t = q - (f32)qi;
    }
    if (t < D_003DF3BC) {
        return 0.0f;
    }
    if (t <= D_003DF40C) {
        return t;
    }
    c->i1 = c->i2;
    c->k1 = c->k2;
    return 0.0f;
}

// best draft for func_0021F1A0 (not a match; do not build from src/)
// range: 0x21F1A0 0x21F400
#include "common.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x0C];
    /* 0x0C */ f32 x0;
    /* 0x10 */ f32 x1;
    /* 0x14 */ f32 pos;
    /* 0x18 */ f32 div18;
    /* 0x1C */ f32 mul1C;
    /* 0x20 */ f32 mul20;
} Cell; /* size 0x24 */

typedef struct {
    /* 0x00 */ s32 count;
    /* 0x04 */ Cell *cells;
    /* 0x08 */ u8 pad08[4];
    /* 0x10 */ f32 scale;
} CellList;

typedef struct {
    /* 0x00 */ Cell *cell;
    /* 0x04 */ f32 f04;
    /* 0x08 */ f32 f08;
    /* 0x0C */ s32 f0C;
} CellOut;

extern f32 D_003DF3BC;
extern f32 D_003DF414;

static inline f32 snap(f32 x) {
    f32 r;
    f32 d;
    f32 res;

    r = (f32)(s32)(x + 0.5f);
    d = x - r;
    if (d < 0.0f) {
        d = -d;
    }
    if (d <= D_003DF3BC) {
        res = r;
    } else {
        res = x;
    }
    return res;
}

s32 func_0021F1A0(CellList *list, CellOut *out, f32 arg2) {
    s32 i;
    s32 cmp;
    Cell *cur;
    Cell *best;
    f32 x0;
    f32 x1;
    f32 len;
    f32 a;
    f32 b;
    f32 c;
    f32 diff;
    f32 t;
    f32 frac;
    f32 y;
    f32 r;
    f32 d;

    best = 0;
    cur = list->cells;
    for (i = 0; i < list->count; i++) {
        if (cur->pos > arg2) {
            break;
        }
        best = cur;
        cur++;
    }
    if (best == 0) {
        return 0;
    }
    x0 = best->x0;
    x1 = best->x1;
    len = 1.0f + (x1 - x0);
    a = snap(len / best->div18);
    b = snap(len / best->div18);
    c = snap(b * best->mul20);
    diff = arg2 - (best->pos + c);
    if (diff <= D_003DF3BC) {
        if (diff < D_003DF414) {
            cmp = -1;
        } else {
            cmp = 0;
        }
    } else {
        cmp = 1;
    }
    if (cmp < 0) {
        y = x0;
        if (x0 != x1) {
            t = (arg2 - best->pos) / a;
            frac = t - (f32)(s32)t;
            y = best->x0 + frac * len;
        }
        r = (f32)(s32)(y + 0.5f);
        d = y - r;
        if (d < 0.0f) {
            d = -d;
        }
        if (d <= D_003DF3BC) {
            out->cell = best;
        } else {
            r = y;
            out->cell = best;
        }
        out->f0C = 0;
        out->f04 = r;
        out->f08 = list->scale * best->mul1C;
        return 1;
    }
    return 0;
}

/* factory-2 2026-11-03, switch form, CLASS structural score=136 (130 words
   differ, 588 vs 564) — B inline / A island correct, B guard inverted.
   See func_0020FE40.md for the diff vs func_0020FE40_best.c (score 130). */
// range: 0x20FE40 0x210074
#include "common.h"

M2C_UNK func_0012C6C0(s32, M2C_UNK *, M2C_UNK *);
M2C_UNK func_0012C7E0();
s32 func_0020E300(s32, u32);
M2C_UNK func_00210730();
extern s32 D_003E08C0;

s32 func_0020FE40(s32 obj) {
    s32 type;
    s32 val;
    s32 rec;
    s32 c;
    s32 v;
    s32 g;

    rec = func_0020E300(obj, *(s32 *)(obj + 0x9C0));
    if (rec == 0) {
        return 0;
    }
    if (*(s32 *)(obj + 0xC) == 0) {
        D_003E08C0 = *(s32 *)(rec + 8);
    }
    c = *(s32 *)(obj + 0xC);
    v = c & 1;
    if (c < 0) {
        if (v != 0) {
            v = v - 2;
        }
    }
    switch (v) {
    case 0:
        if (func_0012C6C0(1, 0, 0) != 0) {
            func_00210730(obj);
            *(s32 *)(rec + 0x18) = 0;
            v = func_0012C7E0(*(s32 *)(obj + 0x9C0), 1, rec + 4, rec + 0x10,
                              rec + 8);
            if (v == 0) {
                *(s32 *)(obj + 0xC) = *(s32 *)(obj + 0xC) + 1;
                return 0;
            }
            if (v == -0xC8) {
                return 0;
            }
            *(s32 *)(obj + 0xC) = *(s32 *)(obj + 0xC) + 2;
        }
        return 0;
    case 1:
        if (func_0012C6C0(1, &type, &val) == 0) {
            return 0;
        }
        *(s32 *)rec = 1;
        *(s32 *)(rec + 0x14) = val;
        *(s32 *)(rec + 0x18) = 1;
        if (val == -2) {
            *(s32 *)(rec + 8) = 0;
        } else if (val == -1) {
            *(s32 *)(rec + 8) = 1;
        } else if (val == 0) {
            *(s32 *)(rec + 0x18) = 0;
        } else if (val < -10) {
            *(s32 *)rec = 0;
        }
        break;
    default:
        return 0;
    }
    *(s32 *)(obj + 0xC) = *(s32 *)(obj + 0xC) + 1;
    if (*(s32 *)(obj + 0xC) >= 2) {
        if (*(s32 *)rec != 0) {
            if (*(s32 *)(rec + 8) != 0) {
                g = D_003E08C0;
                if (g != 0) {
                    if (*(s32 *)(rec + 8) != 0) {
                        *(s32 *)(rec + 0xC) = 0;
                    }
                } else {
                    if (*(s32 *)(rec + 8) != 0) {
                        *(s32 *)(rec + 0xC) = 1;
                    }
                }
                return 1;
            }
        }
    }
    if (*(s32 *)(obj + 0xC) < 10) {
        return 0;
    }
    g = D_003E08C0;
    if (g != 0) {
        if (*(s32 *)(rec + 8) != 0) {
            *(s32 *)(rec + 0xC) = 0;
        }
    }
    if (g == 0) {
        if (*(s32 *)(rec + 8) == 0) {
            *(s32 *)(rec + 0xC) = 0;
        }
    }
    if (g == 0) {
        if (*(s32 *)(rec + 8) != 0) {
            *(s32 *)(rec + 0xC) = 1;
        }
    }
    if (g != 0) {
        if (*(s32 *)(rec + 8) == 0) {
            *(s32 *)(rec + 0xC) = -1;
        }
    }
    return 1;
}

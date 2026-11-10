// range: 0x00177BD0 0x00177E70
#include "common.h"

extern f32 D_003A1490 __attribute__((section(".data")));
extern f32 D_003A1494 __attribute__((section(".data")));
extern f32 D_003A1498 __attribute__((section(".data")));
extern f32 D_004090A0[] __attribute__((section(".data")));
extern f32 D_004090D8 __attribute__((section(".data")));

s32 func_0017AD40(void);

typedef struct {
    /* 0x00 */ char pad_0[0x10];
    /* 0x10 */ f32 f_10;
    /* 0x14 */ f32 f_14;
    /* 0x18 */ f32 f_18;
    /* 0x1C */ f32 f_1C;
} Fx;

typedef struct {
    /* 0x00 */ char pad_0[0x784];
    /* 0x784 */ f32 f_784;
} Owner;

typedef struct {
    /* 0x00 */ s32 f_00;
    /* 0x04 */ char pad_4[4];
    /* 0x08 */ Fx *fx;
    /* 0x0C */ Owner *owner;
} Node;

static inline void Advance(f32 *slot, f32 d, f32 scale) {
    f32 base = *slot;
    f32 val = base * d + scale;

    if (val < base) {
        val = base;
    } else if (255.0f < val) {
        val = 255.0f;
    }
    *slot = val;
}

s32 func_00177BD0(Node *node) {
    Fx *fx;
    Owner *owner;
    f32 scale;

    if (node->f_00 < 4) {
        if (func_0017AD40() == 1) {
            scale = D_004090A0[node->f_00 * 2] / 16.0f;
            fx = node->fx;
            Advance(&fx->f_10, D_003A1490, scale);
            Advance(&fx->f_14, D_003A1494, scale);
            Advance(&fx->f_18, D_003A1498, scale);
            fx->f_1C = 128.0f;
            owner = node->owner;
            if (owner != 0) {
                owner->f_784 = scale;
            }
            return 0;
        }
    }
    if (node->f_00 == 0x20) {
        scale = D_004090D8 / 16.0f;
        fx = node->fx;
        Advance(&fx->f_10, D_003A1490, scale);
        Advance(&fx->f_14, D_003A1494, scale);
        Advance(&fx->f_18, D_003A1498, scale);
        fx->f_1C = 128.0f;
        owner = node->owner;
        if (owner != 0) {
            owner->f_784 = scale;
        }
    }
    return 0;
}

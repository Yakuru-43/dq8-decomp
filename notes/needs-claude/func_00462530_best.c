// range: 0x462530 0x4628E0
#include "common.h"

typedef struct {
    /* 0x00 */ f32 val_00;
    /* 0x04 */ f32 val_04;
    /* 0x08 */ char pad_08[8];
    /* 0x10 */ union {
        u8 raw;
        struct { s8 lo : 4; s8 hi : 4; } nib;
    } type;
    /* 0x12 */ s8 count_12;
    /* 0x13 */ s8 mode_13;
    /* 0x14 */ char pad_14[8];
    /* 0x1C */ f32 val_1C;
    /* 0x20 */ f32 val_20;
    /* 0x24 */ f32 val_24[5];
    /* 0x38 */ s8 flag_38[5];
    /* 0x3D */ char pad_3D[3];
} S_462530;

extern f32 D_003DF394 __attribute__((section(".sdata")));
extern f32 D_003DF4B4 __attribute__((section(".sdata")));
extern f32 D_003DF59C __attribute__((section(".sdata")));
extern f32 D_003DF744 __attribute__((section(".sdata")));
extern f32 D_003DF824 __attribute__((section(".sdata")));
extern f32 D_003DF8D0 __attribute__((section(".sdata")));
extern f32 D_003DF924 __attribute__((section(".sdata")));
extern f32 D_003DF9DC __attribute__((section(".sdata")));
extern f32 D_003DF9E0 __attribute__((section(".sdata")));
extern S_462530 *D_003E1B50 __attribute__((section(".sdata")));
extern char D_421480;

extern s32 func_004628E0(void *arg0, s32 arg1);

void func_00462530(void) {
    S_462530 *entries;
    S_462530 *e;
    s32 i;
    s32 j;
    s8 st;

    entries = D_003E1B50;
    if (entries == 0) {
        return;
    }
    e = entries;
    for (i = 0; i < 24; i++, e++) {
        if (e->type.nib.lo == 0) {
            continue;
        }
        st = e->type.nib.hi;
        if (st == 0 || st == 3 || st == 5) {
            if (func_004628E0(&D_421480, 4) != 0) {
                if (e->flag_38[0] == 2) {
                    continue;
                }
            }
            if (e->mode_13 == 0) {
                e->val_1C += D_003DF8D0;
                e->val_20 += D_003DF8D0;
                if (e->val_1C >= 1.0f) {
                    e->mode_13 = 1;
                }
                if (e->val_1C >= D_003DF824) {
                    e->count_12 = 10;
                }
            }
            if (e->mode_13 == 1) {
                for (j = 0; j < 5; j++) {
                    if (e->flag_38[j] != 0) {
                        if (e->flag_38[j] == 1) {
                            e->val_24[j] += D_003DF9DC;
                            if (D_003DF4B4 <= e->val_24[j]) {
                                e->flag_38[j] = 2;
                                e->val_24[j] = 0.0f;
                            }
                        }
                        if (e->flag_38[j] == 1 && D_003DF924 <= e->val_24[j] &&
                            j > 0) {
                            e->flag_38[j - 1] = 1;
                        }
                    }
                }
                e->val_1C -= D_003DF9E0;
                if (e->val_1C <= 0.0f) {
                    e->val_1C = 0.0f;
                }
                if (e->val_1C <= 0.0f) {
                    if (e->flag_38[0] == 2) {
                        e->type.raw = (e->type.raw & ~0xF) | 0xF;
                    }
                }
            }
            if (e->count_12 > 0) {
                e->count_12--;
            }
        }
        st = e->type.nib.hi;
        if (st == 1 || st == 2 || st == 4) {
            if (func_004628E0(&D_421480, 4) != 0 && e->mode_13 == 1 &&
                e->val_1C < D_003DF744) {
                continue;
            }
            e->val_04 += D_003DF394;
            if (e->mode_13 == 0) {
                e->val_1C += D_003DF8D0;
                e->val_20 += D_003DF8D0;
                if (e->val_1C >= 1.0f) {
                    e->mode_13 = 1;
                }
                if (e->val_1C >= D_003DF824) {
                    e->count_12 = 10;
                }
            }
            if (e->mode_13 == 1) {
                e->val_1C -= D_003DF59C;
                if (e->val_1C <= 0.0f) {
                    e->type.raw = (e->type.raw & ~0xF) | 0xF;
                }
            }
            if (e->count_12 > 0) {
                e->count_12--;
            }
        }
    }
}

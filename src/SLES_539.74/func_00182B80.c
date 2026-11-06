// range: 0x182B80 0x182C60
#include "common.h"

typedef struct {
    /* 0x00 */ u8 pad_00[0x32];
    /* 0x32 */ s16 f_32;
} Flagged;

typedef struct {
    /* 0x00 */ u8 pad_00[0x11];
    /* 0x11 */ u8 f_11;
    /* 0x12 */ u8 pad_12[0x7B4 - 0x12];
    /* 0x7B4 */ Flagged *p_7B4;
    /* 0x7B8 */ Flagged *p_7B8;
    /* 0x7BC */ u8 pad_7BC[4];
    /* 0x7C0 */ s32 f_7C0;
} Entry;

extern s32 D_0040F9B0 __attribute__((section(".data")));
extern s32 D_0040F9B4 __attribute__((section(".data")));
extern Flagged *D_0040F9B8 __attribute__((section(".data")));
extern s32 D_0040F9C4 __attribute__((section(".data")));
extern Entry *D_0040F9D0[16] __attribute__((section(".data")));

void func_00182B80(s32 arg0) {
    s32 i;

    if (D_0040F9B0 == 0) {
        return;
    }
    if (D_0040F9B4 == 0) {
        return;
    }
    D_0040F9C4 = arg0;
    for (i = 0; i < 16; i++) {
        if (D_0040F9D0[i] == 0) {
            continue;
        }
        if (D_0040F9D0[i]->p_7B8 != D_0040F9B8) {
            continue;
        }
        if (arg0 != 0) {
            D_0040F9D0[i]->p_7B4->f_32 = 1;
            D_0040F9D0[i]->p_7B8->f_32 = 1;
            D_0040F9D0[i]->f_7C0 = 1;
            D_0040F9D0[i]->f_11 = 1;
            break;
        } else {
            D_0040F9D0[i]->p_7B4->f_32 = 0;
            D_0040F9D0[i]->p_7B8->f_32 = 0;
            D_0040F9D0[i]->f_7C0 = 0;
            D_0040F9D0[i]->f_11 = 0;
            break;
        }
    }
}

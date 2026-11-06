// range: 0x182C60 0x182D00
#include "common.h"

typedef struct Flagged {
    /* 0x00 */ u8 pad_00[0x32];
    /* 0x32 */ s16 f_32;
} Flagged;

typedef struct {
    /* 0x00 */ s8 f_00;
    /* 0x01 */ u8 pad_01[0x03];
    /* 0x04 */ s32 f_04;
    /* 0x08 */ u8 pad_08[0x7B8 - 0x08];
    /* 0x7B8 */ Flagged *p_7B8;
} Entry;

extern Flagged *D_0040F9B8 __attribute__((section(".data")));
extern Entry *D_0040F9D0[16] __attribute__((section(".data")));

void func_00182C60(s32 arg0) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (D_0040F9D0[i] != 0) {
            D_0040F9D0[i]->p_7B8 = 0;
        }
    }
    for (i = 0; i < 16; i++) {
        if (D_0040F9D0[i] != 0 && D_0040F9D0[i]->f_00 == 1) {
            D_0040F9D0[i]->f_04 = arg0;
            D_0040F9D0[i]->p_7B8 = D_0040F9B8;
            return;
        }
    }
}

// range: 0x157C00 0x157D00
#include "common.h"

extern s64 D_003A0F30[12] __attribute__((section(".data")));

typedef struct {
    /* 00 */ u8 pad_00[0x10];
    /* 10 */ u64 link;
    /* 18 */ u8 pad_18[8];
    /* 20 */ u32 ready : 1;
    /* 20 */ u32 mode : 3;
    /* 20 */ u32 val : 8;
    /* 21 */ u32 pad_21 : 2;
    /* 21 */ u32 f6 : 1;
    /* 21 */ u32 f7 : 1;
    /* 22 */ u32 g0 : 1;
    /* 22 */ u32 g1 : 2;
    /* 23 */ u8 pad_23[0x1D];
    /* 40 */ u8 h0 : 1;
    /* 41 */ u8 pad_41[0x1B];
    /* 5C */ s32 state;
} Obj5C;

/* Put the object in its wait state with the default flags. */
void func_00157C00(Obj5C *o) {
    o->link = D_003A0F30[1];
    o->ready = 1;
    o->mode = 5;
    o->val = 0;
    o->val = 1;
    o->f6 = 0;
    o->f7 = 0;
    o->g0 = 1;
    o->g1 = 2;
    o->h0 = 0;
    o->state = -1;
}

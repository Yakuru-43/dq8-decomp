// range: 0x236C20 0x236DB0
#include "common.h"

struct Meter {
    /* 0x000 */ u8 pad_000[0x1FC];
    /* 0x1FC */ f32 last;
    /* 0x200 */ u8 pad_200[8];
    /* 0x208 */ s32 active;
    /* 0x20C */ f32 speed;
    /* 0x210 */ s32 state;
    /* 0x214 */ s32 tick;
};

void func_00236C20(struct Meter *meter) {
    char *e;
    f32 *slot;
    f32 val;
    s32 i;

    if (meter->active == 0) {
        return;
    }
    i = 0;
    do {
        if (meter->state == 1) {
            if (meter->tick == 0) {
                meter->speed = (128.0f - *(f32 *)((char *)meter + (i << 4) + 0x3C)) / 6.0f;
            }
            e = (char *)meter + (i << 4);
            slot = (f32 *)(e + 0x3C);
            val = meter->speed + *(f32 *)(e + 0x3C);
            if (val < 128.0f) {
                *(f32 *)(e + 0x3C) = val;
            } else {
                *slot = 128.0f;
            }
            if (meter->tick > 6) {
                *slot = 128.0f;
                meter->state = 0;
            }
        }
        if (meter->state == 2) {
            if (meter->tick == 0) {
                meter->speed = -*((f32 *)((char *)meter + (i << 4) + 0x3C)) / 6.0f;
            }
            e = (char *)meter + (i << 4);
            slot = (f32 *)(e + 0x3C);
            val = meter->speed + *(f32 *)(e + 0x3C);
            if (val <= 0.0f) {
                *slot = 0.0f;
            } else {
                *(f32 *)(e + 0x3C) = val;
            }
            if (meter->tick > 6) {
                *slot = 0.0f;
                meter->state = 0;
            }
        }
        meter->last = *(f32 *)((char *)meter + (i << 4) + 0x3C);
    } while (++i < 12);
    if (meter->tick > 45) {
        meter->tick = 0;
    }
    if (meter->state == 0) {
        meter->tick = 0;
    } else {
        meter->tick = meter->tick + 1;
    }
}

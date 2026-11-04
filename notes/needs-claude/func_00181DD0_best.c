// range: 0x181DD0 0x181F20
#include "common.h"

typedef struct TimerObj {
    /* 0x000 */ char pad_000[0x2F4];
    /* 0x2F4 */ f32 f2F4;
    /* 0x2F8 */ f32 f2F8;
    /* 0x2FC */ char pad_2FC[4];
    /* 0x300 */ s32 count300;
    /* 0x304 */ s32 count304;
    /* 0x308 */ s32 count308;
} TimerObj;

void func_00181DD0(TimerObj *arg0, s32 *arg1, s32 arg2, f32 arg3) {
    f32 t;
    f32 step;

    t = arg0->f2F4 + arg3;
    if (t < 0.0f) {
        t = 0.0f;
    }
    arg0->f2F4 = t;
    if (arg1 != 0) {
        *arg1 = 0;
    }
    t = arg0->f2F8 + arg3;
    if (t < 0.0f) {
        t = 0.0f;
    }
    arg0->f2F8 = t;
    step = 56.0f;
    while (step <= arg0->f2F8) {
        if (arg2 != 0) {
            if (0 < arg0->count300) {
                arg0->count300--;
                if (arg0->count300 <= 0) {
                    if (arg1 != 0) {
                        *arg1 = *arg1 | 1;
                    }
                }
            }
            if (0 < arg0->count304) {
                arg0->count304--;
                if (arg0->count304 <= 0) {
                    if (arg1 != 0) {
                        *arg1 = *arg1 | 2;
                    }
                }
            }
            if (0 < arg0->count308) {
                arg0->count308--;
                if (arg0->count308 <= 0) {
                    if (arg1 != 0) {
                        *arg1 = *arg1 | 8;
                    }
                }
            }
        }
        arg0->f2F8 = arg0->f2F8 - step;
    }
}

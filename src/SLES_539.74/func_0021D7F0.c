// range: 0x21D7F0 0x21D880
#include "common.h"

typedef struct Timed {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 pad_01[0x13];
    /* 0x14 */ s8 mode;
    /* 0x15 */ u8 pad_15[3];
    /* 0x18 */ f32 val;
} Timed;

void func_0021D7F0(Timed *self) {
    if (self->active != 0) {
        if (self->mode != 0) {
            if (self->mode == 1) {
                self->val += 1.0f;
                if (1.0f < self->val) {
                    self->val = 1.0f;
                }
            }
        } else {
            self->val -= 1.0f;
            if (self->val < 0.0f) {
                self->val = 0.0f;
            }
        }
        return;
    }
}

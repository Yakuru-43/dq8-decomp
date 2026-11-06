// range: 0x00375F80 0x00376080
#include "common.h"

typedef struct {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u8 pad_02[2];
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u8 pad_16[2];
} Cell_00375F80;

extern f32 D_003E0098;

void func_00375F80(Cell_00375F80 *cell, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, f32 arg6, f32 arg7) {
    cell->unk04 = (f32)arg3;
    cell->unk08 = (f32)arg4;
    cell->unk14 = (u16)arg5;
    if (arg5 == 1) {
        if (arg3 < arg1) {
            if (0.0f < arg6) {
                arg6 = arg6 * -1.0f;
            }
        }
        if (arg4 < arg2) {
            if (0.0f < arg7) {
                arg7 = arg7 * -1.0f;
            }
        }
    }
    cell->unk0C = arg6 * D_003E0098;
    cell->unk10 = arg7 * D_003E0098;
    if (arg5 == 2) {
        cell->unk0C = ((f32)arg1 - cell->unk04) / arg6;
        cell->unk10 = ((f32)arg2 - cell->unk08) / arg7;
    }
    cell->flags |= 1;
}

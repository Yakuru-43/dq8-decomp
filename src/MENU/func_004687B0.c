// range: 0x4687B0 0x4689B0
#include "common.h"

extern f32 D_003DF390;
extern f32 D_003DF398;
extern f32 D_003DF3F4;
extern s8 D_003E1AE0;

s32 func_2D34C0();                                   /* extern */
M2C_UNK func_2D38E0(s32, s32, s32, s32);             /* extern */
M2C_UNK func_2D4480(s32, s32, s32, s32);             /* extern */
M2C_UNK func_2D4740(s32, s32, f32, f32, f32);        /* extern */
M2C_UNK func_2D48B0(s32, s32, f32);                  /* extern */
M2C_UNK func_2D6B20(s32, s32, s32, s32, s32);        /* extern */
M2C_UNK func_2D7120(s32, s32, s32, s32);             /* extern */
M2C_UNK func_37D780(s32);                            /* extern */
M2C_UNK func_004689B0();                             /* extern */
M2C_UNK func_00468F10(s8);                           /* extern */
M2C_UNK func_00469890();                             /* extern */

void func_004687B0(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_2D34C0();
    if (arg0 == 0) {
        func_2D4480(temp_s0, 0x4A2, 0x49C, 1);
        func_2D7120(temp_s0, 0x4A2, 0x32, -0x12);
        func_2D4480(temp_s0, 0x586, 0x585, 1);
        func_2D6B20(temp_s0, 0x585, 0x49C, 0, 0);
        func_2D7120(temp_s0, 0x4A1, 0x1E, 0x10C);
        func_2D38E0(temp_s0, 0x585, 1, -1);
        func_2D38E0(temp_s0, 0x49C, 1, -1);
        func_2D4740(temp_s0, 0x585, 1.0f, D_003DF3F4, 0.0f);
        func_2D4740(temp_s0, 0x4A2, 1.0f, D_003DF3F4, 0.0f);
        func_2D4740(temp_s0, 0x49C, 1.0f, D_003DF390, 0.0f);
        func_00468F10(D_003E1AE0);
        func_00469890();
        func_004689B0();
        func_37D780(0);
    } else if (arg0 == 1) {
        func_2D4740(temp_s0, 0x585, 0.0f, D_003DF390, -1.0f);
        func_2D4740(temp_s0, 0x4A2, 0.0f, D_003DF398, -1.0f);
        func_2D4740(temp_s0, 0x49C, 0.0f, D_003DF398, -1.0f);
    } else if (arg0 == 2) {
        func_2D38E0(temp_s0, 0x585, 0, -1);
        func_2D38E0(temp_s0, 0x49C, 0, -1);
        func_2D48B0(temp_s0, 0x49C, 1.0f);
    }
}

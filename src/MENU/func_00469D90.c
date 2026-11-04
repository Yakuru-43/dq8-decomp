// range: 0x469D90 0x469EC0
#include "common.h"

s32 func_2D34C0(void);                                                /* extern */
M2C_UNK func_2D6430(M2C_UNK, s32, s32, s32, s32, s32);               /* extern */
M2C_UNK func_2D6390(M2C_UNK, s32, s32, s32, s32, s32, s32, f32);     /* extern */
M2C_UNK func_374130(s32, s32, s32, s32, s32);                        /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));
extern f32 D_004787A0 __attribute__((section(".data")));
extern f32 D_004787A4 __attribute__((section(".data")));
extern f32 D_004787A8 __attribute__((section(".data")));
extern s8 D_3E01B4[] __attribute__((section(".sdata")));

void func_00469D90(s32 arg0, s32 arg1) {
    union { f32 f; s32 i; } vals[3];
    s32 handle;
    s32 val;
    s8 *p;

    vals[0].f = D_004787A0;
    vals[1].f = D_004787A4;
    vals[2].f = D_004787A8;
    handle = func_2D34C0();
    val = vals[arg0].i;
    if (arg1 != 0) {
        func_2D6430(handle, val, 0, 0x18703, -0x21, -2);
    } else {
        func_2D6390(handle, val, 0, 0x18703, -0x21, -2, 0, D_003DF744);
    }
    p = &D_3E01B4[arg0];
    func_2D6430(handle, val, *p, 0x18700, -4, 1);
    func_374130(0x18701, val, 0, *p, 8);
    func_374130(0x18700, val, 0, *p, 0xE);
}

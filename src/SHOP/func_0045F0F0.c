// range: 0x45F0F0 0x45F190
#include "common.h"

void func_0045F190(void *, s16);                     /* extern */
void func_13E090(void *);                            /* extern */
void func_166130(void *);                            /* extern */
void func_1661A0(void *, void *, s32);               /* extern */
void func_166270(void *, void *);                    /* extern */
void func_166420(void *);                            /* extern */

extern s16 D_003E19C8 __attribute__((section(".sdata")));
extern M2C_UNK D_00470AC0 __attribute__((section(".data")));
extern M2C_UNK D_00473770 __attribute__((section(".data")));
extern M2C_UNK D_00474460 __attribute__((section(".data")));

union Param4450 {
    /* 0x00 */ u128 q;
    /* 0x00 */ u32 unkC[4];
};
extern union Param4450 D_00474450 __attribute__((section(".data")));

void func_0045F0F0(void *arg0, s32 arg1, s32 arg2) {
    u8 win[0xED0];

    if (arg0 == 0) {
        return;
    }
    D_003E19C8 = arg2;
    func_0045F190(&D_00473770, D_003E19C8);
    D_00474450.q = 0;
    D_00474450.unkC[3] = 0x3F800000;
    func_13E090(&D_00474460);
    func_166130(win);
    func_166270(win, &D_00470AC0);
    func_1661A0(win, arg0, arg1);
    func_166420(win);
}

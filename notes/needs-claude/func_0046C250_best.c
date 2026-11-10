// range: 0x46C250 0x46C3E0
#include "common.h"

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_3791B0(S_arg0 *arg0);                              /* extern */
s32 func_3794B0(void);                                      /* extern */
void func_370C00(s32 arg0, s32 arg1, s32 arg2);             /* extern */
void func_2D38E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);   /* extern */
void func_0046B340(u32 arg0);
s32 func_0046DD10(void);
s32 func_0046DE00(void);
s32 func_2B1630(s32 arg0, s8 arg1, s32 *arg2);              /* extern */
void func_2B11B0(s32 arg0, s8 arg1);                        /* extern */
void func_2B1040(s32 arg0, s8 arg1, s32 arg2, s32 arg3);    /* extern */
extern s8 D_003E19FC;
extern s16 D_003E1A00;
extern s16 D_003E1A04;
extern s32 D_003E1A08;
extern s32 D_003E1A0C;

s32 func_0046C250(S_arg0 *arg0, s32 arg1) {
    s32 entries[4];
    s32 flag;
    s32 list;
    s32 i;
    s32 count;

    if (func_3791B0(arg0) != 0) {
        func_2D38E0(arg1, 0x2733, 0, -1);
        func_2D38E0(arg1, 0x2730, 0, -1);
        func_2D38E0(arg1, 0x2745, 0, -1);
        flag = 0;
        if (func_0046DD10() == 1) {
            func_0046B340(0);
            flag = 1;
        }
        if (func_3794B0() != 0) {
            func_370C00(arg0->unk20, D_003E1A0C, 0);
        } else {
            list = func_0046DE00();
            count = func_2B1630(list, D_003E19FC, entries);
            func_2B11B0(list, D_003E19FC);
            for (i = 0; i < count; i++) {
                if (D_003E1A00 == entries[i]) {
                    entries[i] = D_003E1A04;
                    D_003E1A04 = -1;
                }
                func_2B1040(list, D_003E19FC, entries[i], -1);
            }
            if (0 < D_003E1A04) {
                func_2B1040(list, D_003E19FC, D_003E1A04, -1);
            }
            func_370C00(arg0->unk20, D_003E1A08, flag);
        }
    }
    return 1;
}

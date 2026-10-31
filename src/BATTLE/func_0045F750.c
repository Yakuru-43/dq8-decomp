// range: 0x45F750 0x45F840
#include "common.h"

extern f32 D_003DF954 __attribute__((section(".sdata")));
extern f32 D_003DF6EC __attribute__((section(".sdata")));

void func_0045F840(void *);

typedef struct {
    f32 val_00;
    s8 flag_04;
    char pad_05[7];
    f32 val_0C;
    f32 val_10;
} S_45F750;

void func_0045F750(S_45F750 *arg0, s32 arg1, s32 arg2) {
    s32 flag;

    flag = 1;
    if ((20.0f <= arg0->val_00) || (arg0->val_00 < 8.0f)) {
        flag = 0;
    }
    if (arg0->flag_04 == 0) {
        flag = 0;
    }
    if (flag == 0) {
        return;
    }
    switch (arg1) {
    case 0:
        arg0->val_0C = 0.5f;
        arg0->val_10 = 1.0f;
        break;
    case 1:
        arg0->val_0C = D_003DF954;
        arg0->val_10 = 1.0f;
        break;
    case 2:
        arg0->val_0C = D_003DF6EC;
        arg0->val_10 = 1.0f;
        break;
    }
    if (arg2 == 1) {
        func_0045F840(arg0);
    }
}

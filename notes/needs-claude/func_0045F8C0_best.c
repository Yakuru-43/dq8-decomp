// range: 0x45F8C0 0x45F9B0
// best attempt (2/20, score 107): allocation correct, loop-1 layout off by 12 B
#include "common.h"

extern s16 *D_003E1B7C __attribute__((section(".sdata")));
extern s32 D_004853E0[4];

s32 func_0015F490(void);
void func_001419A0(s32, s16, f32);
s32 func_00465710(s32);
void func_004652C0(s32);
void func_00465340(s32);

void func_0045F8C0(void) {
    s32 i;
    s32 count;

    if (D_003E1B7C == 0) {
        return;
    }
    count = 0;
    for (i = 0; i < 4; i++) {
        if (D_004853E0[i] == 0) {
            continue;
        }
        if (func_00465710(D_004853E0[i]) == 0) {
            continue;
        }
        count++;
    }
    if (count > 0) {
        func_001419A0(func_0015F490(), *D_003E1B7C, 1.0f);
        for (i = 0; i < 4; i++) {
            if (D_004853E0[i] == 0) {
                continue;
            }
            func_004652C0(D_004853E0[i]);
            func_00465340(D_004853E0[i]);
        }
    }
}

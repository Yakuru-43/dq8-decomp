// range: 0x45FA60 0x45FB90
#include "common.h"

extern void *D_003E1B7C __attribute__((section(".sdata")));
extern s32 D_004853E0[4];

extern s32 func_14EB30(s32 size, void *arg1);
extern s32 func_0045FB90(s32 arg0);
void func_00464F80(s32 arg0, void *arg1, s32 arg2, s32 arg3);
void func_00465270(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6);

typedef struct {
    s16 count;
} S_45FA60;

void func_0045FA60(void *arg0, S_45FA60 *arg1) {
    s32 count;
    s32 i;
    s32 handle;

    if (arg0 == 0) {
        return;
    }
    if (arg1 == 0) {
        return;
    }
    D_003E1B7C = arg1;
    count = arg1->count;
    for (i = 0; i < 4; i++) {
        handle = func_14EB30(0xA0, arg0);
        if (handle != 0) {
            handle = func_0045FB90(handle);
        }
        D_004853E0[i] = handle;
        func_00464F80(D_004853E0[i], arg0, 8, 8);
    }
    func_00465270(D_004853E0[0], count, D_003E1B7C, 0, 0, 0x40, 0x20);
    func_00465270(D_004853E0[1], count, D_003E1B7C, 0, 0, 0x40, 0x20);
    func_00465270(D_004853E0[2], count, D_003E1B7C, 0x40, 0, 0x40, 0x20);
    func_00465270(D_004853E0[3], count, D_003E1B7C, 0, 0x20, 0x40, 0x20);
}

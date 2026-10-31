// range: 0x47E540 0x47E590
#include "common.h"

s32 func_133F78(s32, M2C_UNK *);                    /* extern */
extern M2C_UNK D_00484A08 __attribute__((section(".data")));
extern s32 D_00421A00 __attribute__((section(".data")));

typedef struct {
    char pad0[0x50];
    s32 unk50;
} S_arg2;

s32 func_0047E540(s32 arg0, s32 arg1, S_arg2 *arg2) {
    if (func_133F78(arg2->unk50, &D_00484A08) == 0) {
        D_00421A00 = 0;
    } else {
        D_00421A00 = 1;
    }
    return 0;
}

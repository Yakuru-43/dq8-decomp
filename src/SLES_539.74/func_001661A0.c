// range: 0x1661A0 0x166220
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00134598();         /* extern */
M2C_UNK func_00165760();                      /* extern */
extern M2C_UNK D_003C2750 __attribute__((section(".data")));

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char pad10[0x14];
    s32 unk24;
} S_arg0;

void func_001661A0(S_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk0 = arg1;
    arg0->unk4 = arg2;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk24 = 0;
    if (func_00134598(arg1, &D_003C2750, 3) != 0) {
        func_00165760(arg0);
    } else {
        arg0->unk24 = 1;
        arg0->unk8 = (s32) (arg0->unk8 + 4);
    }
}

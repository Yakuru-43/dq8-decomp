// range: 0x47F4A0 0x47F560
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_133F78(s32, M2C_UNK *);                    /* extern */
M2C_UNK func_2CD030(s32, s32, M2C_UNK);             /* extern */
extern M2C_UNK D_00484A10 __attribute__((section(".data")));
extern M2C_UNK D_00484C40 __attribute__((section(".data")));
extern M2C_UNK D_00484C48 __attribute__((section(".data")));
extern M2C_UNK D_00484C50 __attribute__((section(".data")));

typedef struct {
    char pad0[0x50];
    s32 unk50;
    s32 unk54;
} S_arg2;

typedef struct {
    char pad0[0x4];
    s32 unk4;
} S_arg1;

s32 func_0047F4A0(s32 arg0, S_arg1 *arg1, S_arg2 *arg2) {
    M2C_UNK var_s0;

    var_s0 = 0;
    if (func_133F78(arg2->unk54, &D_00484C40) == 0) {
        var_s0 = 4;
    }
    if (func_133F78(arg2->unk50, &D_00484C48) == 0) {
        func_2CD030(arg0, arg1->unk4, var_s0);
    } else if (func_133F78(arg2->unk50, &D_00484C50) != 0) {
        func_133F78(arg2->unk50, &D_00484A10);
    }
    return 0;
}

// range: 0x30C320 0x30C3A0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0029C6D0(M2C_UNK *);                   /* extern */
M2C_UNK func_0030C310(M2C_UNK *, s32);              /* extern */
f32 func_00327760(s32, s32);                        /* extern */
s32 func_00340B80(M2C_UNK *);                       /* extern */
M2C_UNK func_003568F0(s32, f32);                    /* extern */
s32 func_0035D590(s32);                             /* extern */

typedef struct {
    char pad0[0x158];
    s32 unk158;
} S_arg1;

void func_0030C320(s32 arg0, S_arg1 *arg1) {
    M2C_UNK sp4C;
    s32 temp_s0;

    temp_s0 = func_0035D590(arg1->unk158);
    func_0029C6D0(&sp4C);
    func_0030C310(&sp4C, arg1->unk158);
    func_003568F0(arg0, func_00327760(temp_s0, func_00340B80(&sp4C)));
}

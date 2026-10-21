// range: 0x46AF40 0x46AFD0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0046A510(s32);                         /* extern */
M2C_UNK func_0046B340(M2C_UNK);                     /* extern */
M2C_UNK func_0046B3D0();                            /* extern */
M2C_UNK func_0046B420(s32, M2C_UNK);                /* extern */
s32 func_0046B4A0();                                /* extern */
M2C_UNK func_0046DE00();                            /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_3715D0(s32);                               /* extern */

typedef struct {
    char pad0[0x18];
    s32 unk18;
} S_arg0;

void func_0046AF40(S_arg0 *arg0, M2C_UNK arg1) {
    func_0046DE00();
    func_2D38E0(arg1, 0x2733, 0, -1);
    func_2D38E0(arg1, 0x1F6D, 1, -1);
    func_0046B340(1);
    func_0046B420(func_3715D0(arg0->unk18), 1);
    func_0046A510(func_0046B4A0());
    func_0046B3D0();
}

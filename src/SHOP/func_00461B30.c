// range: 0x461B30 0x461BA0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_004626B0();                            /* extern */
M2C_UNK func_22A920(M2C_UNK);                       /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK func_37DF40(M2C_UNK);                       /* extern */
extern M2C_UNK D_004736C0 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_00461B30(S_arg0 *arg0, M2C_UNK arg1) {
    func_22A920(0);
    func_2D38E0(arg1, 0x485, 0, -1);
    func_37DF40(0);
    func_004626B0();
    func_370C00(arg0->unk20, &D_004736C0, 0);
    return 1;
}

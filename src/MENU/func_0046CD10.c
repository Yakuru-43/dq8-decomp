// range: 0x46CD10 0x46CD70
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK func_37CEA0(M2C_UNK);                       /* extern */
extern M2C_UNK D_00479450 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_0046CD10(S_arg0 *arg0, M2C_UNK arg1) {
    func_2D38E0(arg1, 0x4A6, 0, -1);
    func_37CEA0(0);
    func_370C00(arg0->unk20, &D_00479450, 0);
    return 1;
}

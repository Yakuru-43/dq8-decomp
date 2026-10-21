// range: 0x460090 0x4600F0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK func_37DF00(M2C_UNK);                       /* extern */
extern M2C_UNK D_00478F90 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_00460090(S_arg0 *arg0, M2C_UNK arg1) {
    func_2D38E0(arg1, 0x486, 0, -1);
    func_37DF00(0);
    func_370C00(arg0->unk20, &D_00478F90, 0);
    return 1;
}

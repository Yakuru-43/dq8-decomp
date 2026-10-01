// range: 0x2109E0 0x210A40
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00133CB8(s32, M2C_UNK *);              /* extern */
M2C_UNK func_00210A40();                            /* extern */
extern M2C_UNK D_003C7920 __attribute__((section(".data")));
extern M2C_UNK D_003C7A58 __attribute__((section(".data")));

void func_002109E0(s32 arg0, s32 arg1, s32 arg2) {
    func_00210A40();
    if (arg2 == 0) {
        func_00133CB8(arg0, &D_003C7920);
        return;
    }
    func_00133CB8(arg0, &D_003C7A58);
}

// range: 0x15FF20 0x15FFA0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00133CB8(s8 *, M2C_UNK *);             /* extern */
M2C_UNK func_001340C0(s8 *, M2C_UNK *);             /* extern */
u32 func_001341D8();                                /* extern */
extern M2C_UNK D_003C23D8 __attribute__((section(".data")));
extern M2C_UNK D_003C23E0 __attribute__((section(".data")));
extern s8 D_003F80C0 __attribute__((section(".data")));

void func_0015FF20(M2C_UNK *arg0) {
    if (func_001341D8() < 0x38U) {
        D_003F80C0 = 0;
    }
    func_001340C0(&D_003F80C0, &D_003C23D8);
    func_00133CB8(&D_003F80C0, arg0);
    func_00133CB8(&D_003F80C0, &D_003C23E0);
}

// range: 0x163E10 0x163E70
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00133CB8(M2C_UNK *, s8 *);             /* extern */
M2C_UNK func_001340C0(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK D_003F25B0 __attribute__((section(".data")));
extern M2C_UNK D_003F26B0 __attribute__((section(".data")));

void func_00163E10(s8 *arg0) {
    s8 *var_s0;

    var_s0 = arg0;
    func_001340C0(&D_003F26B0, &D_003F25B0);
    if (var_s0 != NULL) {
        if (*var_s0 == 0x2F) {
            var_s0 += 1;
        }
        func_00133CB8(&D_003F26B0, var_s0);
    }
}

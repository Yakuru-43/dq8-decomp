// range: 0x3244B0 0x3244D0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00321900(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK D_003ADA50 __attribute__((section(".data")));
extern M2C_UNK D_004532D0 __attribute__((section(".data")));

void func_003244B0(void) {
    func_00321900(&D_004532D0, &D_003ADA50);
}

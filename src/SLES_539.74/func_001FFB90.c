// range: 0x1FFB90 0x1FFBA0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001FFBA0(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));

void func_001FFB90(s32 arg0) {
    func_001FFBA0(&D_0042CDB0, arg0);
}

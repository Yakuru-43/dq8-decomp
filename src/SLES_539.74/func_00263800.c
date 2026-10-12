// range: 0x263800 0x263830
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_002614B0(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_0041E470 __attribute__((section(".data")));

void func_00263800(s32 arg0) {

    if (!(arg0 != 0)) {
        return;
    }

    func_002614B0(&D_0041E470, arg0);
}

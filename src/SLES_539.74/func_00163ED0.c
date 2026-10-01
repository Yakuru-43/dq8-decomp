// range: 0x163ED0 0x163F40
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(M2C_UNK *, M2C_UNK *);        /* extern */
u32 func_001341D8();                                /* extern */
extern M2C_UNK D_003C26C8 __attribute__((section(".data")));
extern M2C_UNK D_003F24B0 __attribute__((section(".data")));

void func_00163ED0(M2C_UNK *arg0) {
    if ((arg0 != NULL) && (func_001341D8() < 0x100U)) {
        func_001340C0(&D_003F24B0, arg0);
    } else {
        func_001340C0(&D_003F24B0, &D_003C26C8);
    }
}

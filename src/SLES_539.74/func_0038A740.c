// range: 0x38A740 0x38A780
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0037BC00(M2C_UNK *);                       /* extern */
extern M2C_UNK D_004593D0 __attribute__((section(".data")));

s32 func_0038A740(void) {
    if (&D_004593D0 != NULL) {
        return func_0037BC00(&D_004593D0);
    }
    return 1;
}

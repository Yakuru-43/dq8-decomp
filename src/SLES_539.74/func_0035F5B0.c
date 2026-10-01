// range: 0x35F5B0 0x35F5E0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0029D170(M2C_UNK *);                       /* extern */
extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));

s32 func_0035F5B0(void) {
    return func_0029D170(&D_0042CDB0) + 1;
}

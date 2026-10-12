// range: 0x342830 0x342840
// auto: m2c draft, verified byte-exact
#include "common.h"

extern char *D_0042CDB0 __attribute__((section(".data")));

s32 func_00342830(void) {
    return M2C_FIELD(D_0042CDB0, s32 *, 0xC);
}

// range: 0x1EB180 0x1EB1B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern void *D_003E0748;

s32 func_001EB180(void) {
    M2C_FIELD(D_003E0748, s32 *, 0x188) = func_001667C0();
    return 1;
}

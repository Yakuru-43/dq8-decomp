// range: 0x1EBC10 0x1EBC40
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern void *D_003E0748;

s32 func_001EBC10(void) {
    M2C_FIELD(D_003E0748, s32 *, 0x98) = func_001667C0();
    return 1;
}

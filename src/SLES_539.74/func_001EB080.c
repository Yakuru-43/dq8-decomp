// range: 0x1EB080 0x1EB0B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern void *D_003E0748;

s32 func_001EB080(void) {
    M2C_FIELD(D_003E0748, s32 *, 0x19C) = func_001667C0();
    return 1;
}

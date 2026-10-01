// range: 0x1CBD50 0x1CBD80
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0016AF30(void *, s32);                     /* extern */
extern void *D_003E0664;

s32 func_001CBD50(void) {
    return func_0016AF30(D_003E0664, M2C_FIELD(D_003E0664, s32 *, 0x44B4)) != 0;
}

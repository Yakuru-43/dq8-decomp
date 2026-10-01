// range: 0x1A2160 0x1A2190
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0016AF30(void *, s32);                     /* extern */
extern void *D_003E0664;

s32 func_001A2160(void) {
    if (D_003E0664 == NULL) {
        return 0;
    }
    return func_0016AF30(D_003E0664, M2C_FIELD(D_003E0664, s32 *, 0x44B4));
}

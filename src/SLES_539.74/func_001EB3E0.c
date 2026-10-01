// range: 0x1EB3E0 0x1EB420
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern void *D_003E0758;

s32 func_001EB3E0(void) {
    if (D_003E0758 == NULL) {
        return 0;
    }
    M2C_FIELD(D_003E0758, s32 *, 0x1A0) = func_001667C0();
    return 1;
}

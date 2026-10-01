// range: 0x211D50 0x211D90
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern void *D_003E0950;

s32 func_00211D50(void) {
    if (D_003E0950 == NULL) {
        return 0;
    }
    M2C_FIELD(D_003E0950, s32 *, 0x64) = func_001667C0();
    M2C_FIELD(D_003E0950, s32 *, 0x60) = 1;
    return 1;
}

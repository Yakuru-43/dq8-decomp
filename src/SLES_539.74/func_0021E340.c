// range: 0x21E340 0x21E380
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern void *D_003E09DC;

s32 func_0021E340(void) {
    if (D_003E09DC == NULL) {
        return 0;
    }
    M2C_FIELD(D_003E09DC, s32 *, 0x10) = func_001667C0();
    return 1;
}

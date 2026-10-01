// range: 0x1EB810 0x1EB830
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 *D_003E0758;

s32 func_001EB810(void) {
    if (D_003E0758 == NULL) {
        return 0;
    }
    *D_003E0758 = 0x42500000;
    return 1;
}

// range: 0x2C67E0 0x2C6800
// auto: m2c, verified byte-exact
#include "common.h"

extern void *D_003E0434;
extern s32 D_003E0818;

void func_002C67E0(void) {
    D_003E0818 = 0;
    if (D_003E0434 != NULL) {
        M2C_FIELD(D_003E0434, s32 *, 0x1754) = 0;
    }
}

// range: 0x1D6EC0 0x1D6EF0
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 D_004148A0 __attribute__((section(".data")));
extern s8 D_004148A1 __attribute__((section(".data")));

s8 func_001D6EC0(void) {
    if (D_004148A0 == 0) {
        return 0;
    }
    return D_004148A1;
}

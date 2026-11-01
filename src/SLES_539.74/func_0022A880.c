// range: 0x22A880 0x22A8D0
// flags: -flag divbyzerocheck
#include "common.h"

s32 func_0012D4C0(void);

s32 func_0022A880(void) {
    s32 digits = 1;
    s32 n = func_0012D4C0();

    while (n >= 10) {
        n /= 10;
        digits++;
    }
    return digits;
}

// range: 0x200FD0 0x201090
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_004159A0 __attribute__((section(".data")));

s32 func_00200FD0(void) {
    if ((D_004159A0 != 0x15) && (D_004159A0 != 0x14) && (D_004159A0 != 0x16) && (D_004159A0 != 0x13) && (D_004159A0 != 9) && (D_004159A0 != 0xC) && (D_004159A0 != 0xD) && (D_004159A0 != 0xA) && (D_004159A0 != 4) && (D_004159A0 != 5) && (D_004159A0 != 0x19) && (D_004159A0 != 0x1D) && (D_004159A0 != 0x1F)) {
        return 0;
    }
    return 1;
}

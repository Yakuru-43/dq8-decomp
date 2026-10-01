// range: 0x200200 0x200270
// auto: m2c draft, verified byte-exact
#include "common.h"

extern char *D_003E0868;
extern s32 D_004159A4 __attribute__((section(".data")));

void func_00200200(s32 arg0, s32 *arg1) {
    s32 temp_a0;

    if ((D_004159A4 == 3) || (M2C_FIELD(D_003E0868, s16 *, 0x94) == 6) || (D_004159A4 == 0x17)) {
        temp_a0 = *arg1;
        if (temp_a0 & 4) {
            *arg1 = temp_a0 | 1;
            *arg1 &= ~4;
        }
    }
}

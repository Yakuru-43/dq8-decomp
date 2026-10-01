// range: 0x1D6EF0 0x1D6F70
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001D91E0(s32);                         /* extern */
M2C_UNK func_001D9F90(s32);                         /* extern */
extern s32 D_003E071C;
extern s8 D_004148A0 __attribute__((section(".data")));
extern s8 D_004148A2 __attribute__((section(".data")));
extern s8 D_004148A3 __attribute__((section(".data")));

void func_001D6EF0(void) {
    if ((D_004148A0 != 0) && (D_003E071C != 0)) {
        if (D_004148A3 != 1) {
            if (!(D_004148A2 & 1)) {
                func_001D91E0(D_003E071C);
            }
            func_001D9F90(D_003E071C);
            return;
        }
        func_001D9F90(D_003E071C);
    }
}

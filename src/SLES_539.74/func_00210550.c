// range: 0x210550 0x2105C0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00210380(void *);                      /* extern */
M2C_UNK func_002107B0(void *);                      /* extern */

void func_00210550(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    if (arg1 == 1) {
        M2C_FIELD(arg0, s32 *, 0x9DC) = 0xB;
    }
    if (arg1 == 5) {
        func_00210380(arg0);
        func_002107B0(arg0);
    }
}

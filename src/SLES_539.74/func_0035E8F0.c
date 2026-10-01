// range: 0x35E8F0 0x35E950
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0029A100(M2C_UNK *, u8);                   /* extern */
extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));

void func_0035E8F0(void *arg0, void *arg1) {
    if (arg1 != NULL) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(arg1, u8 *, 1);
        M2C_FIELD(arg0, s32 *, 0xC) = (s32) M2C_FIELD(arg1, u8 *, 2);
        M2C_FIELD(arg0, void **, 0x288) = arg1;
        M2C_FIELD(arg0, s32 *, 0x28C) = func_0029A100(&D_0042CDB0, M2C_FIELD(arg1, u8 *, 0xE));
        M2C_FIELD(arg0, s8 *, 0x270) = 5;
    }
}

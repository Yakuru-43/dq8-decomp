// range: 0x278AC0 0x278B10
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00220030(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_00220700(s32, s32, M2C_UNK);           /* extern */
extern M2C_UNK D_00415A40 __attribute__((section(".data")));

void func_00278AC0(void *arg0, s32 arg1) {
    func_00220700(M2C_FIELD(arg0, s32 *, 0x360), M2C_FIELD(arg0, s32 *, 0x10) + arg1, 0);
    func_00220030(&D_00415A40, 1);
    M2C_FIELD(arg0, s16 *, 4) = 0x5A;
}

// range: 0x1BDBF0 0x1BDC60
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0014E320(s32);                         /* extern */
s32 func_0014E360(s32, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_0014E500(s32, s32);                    /* extern */
M2C_UNK func_00255870(void *, s32);                 /* extern */
extern void *D_003E0664;

s32 func_001BDBF0(void) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s0 = M2C_FIELD(D_003E0664, s32 *, 0x548);
    temp_s1 = func_0014E360(temp_s0, 2, 0, 0x40);
    func_0014E320(temp_s0);
    func_0014E500(temp_s0, temp_s1);
    func_00255870(D_003E0664, temp_s1);
    return 1;
}

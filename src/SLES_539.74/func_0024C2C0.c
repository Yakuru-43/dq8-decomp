// range: 0x24C2C0 0x24C310
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(s32, M2C_UNK, s32);           /* extern */
s32 func_0014EA80(s32, s32);                        /* extern */
s16 func_001667C0();                                /* extern */
extern s16 D_003E0B58;
extern s32 D_003E0B5C;
extern s32 D_003E0B70;

s32 func_0024C2C0(void) {
    s32 temp_v0;

    D_003E0B58 = func_001667C0();
    temp_v0 = func_0014EA80(D_003E0B58 * 0x10, D_003E0B70);
    D_003E0B5C = temp_v0;
    func_00131188(temp_v0, 0, D_003E0B58 * 0x10);
    return 1;
}

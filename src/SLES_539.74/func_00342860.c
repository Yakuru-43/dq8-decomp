// range: 0x342860 0x3428D0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00300CB0(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_003CBEE0 __attribute__((section(".data")));
extern s32 D_0042CDBC __attribute__((section(".data")));
extern s32 D_0042CDD8 __attribute__((section(".data")));

s32 func_00342860(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if ((var_a0 < 0) || (var_a0 >= D_0042CDD8)) {
        func_00300CB0(0, &D_003CBEE0, 0xD6);
        var_a0 = 0;
    }
    return D_0042CDBC + (var_a0 * 0x12);
}

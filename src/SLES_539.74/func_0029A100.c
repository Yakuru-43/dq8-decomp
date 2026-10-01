// range: 0x29A100 0x29A170
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00300CB0(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_003CBEE0 __attribute__((section(".data")));

s32 func_0029A100(void *arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = arg1;
    if ((var_a1 < 0) || (var_a1 >= M2C_FIELD(arg0, s32 *, 0x28))) {
        func_00300CB0(0, &D_003CBEE0, 0xD6);
        var_a1 = 0;
    }
    return M2C_FIELD(arg0, s32 *, 0xC) + (var_a1 * 0x12);
}

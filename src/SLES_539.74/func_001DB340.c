// range: 0x1DB340 0x1DB3C0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_001D5A10();                     /* extern */
M2C_UNK func_001D5BA0();                 /* extern */

typedef struct {
    char pad0[0x3C];
    s32 unk3C;
    char pad40[0x14];
    s32 unk54;
} S_arg0;

s32 func_001DB340(S_arg0 *arg0) {
    s32 temp_a1;
    s32 temp_v1;
    s32 var_v0;

    temp_a1 = arg0->unk54;
    if (temp_a1 >= 0) {
        goto block_1;
    }
    if (arg0->unk3C == 1) {
        return 1;
    }
block_1:
    if (temp_a1 < 0) {
        func_001D5BA0(arg0, temp_a1);
        var_v0 = arg0->unk3C;
    } else {
        temp_v1 = func_001D5A10(arg0, temp_a1) != 0;
        arg0->unk54 = -1;
        var_v0 = (temp_v1 ^ 1) & 0xFF;
    }
    return var_v0;
}

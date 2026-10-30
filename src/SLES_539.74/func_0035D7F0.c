// range: 0x35D7F0 0x35D830
#include "common.h"

extern f32 D_003DF448;
extern f32 D_003DF44C;

f32 func_0035D7F0(char *arg0) {
    f32 var_f0;
    s32 temp_v1;

    temp_v1 = *(s32 *)(arg0 + 0x9C);
    var_f0 = 0.0f;
    if (temp_v1 & 0x40) {
        var_f0 = D_003DF44C;
    } else if (temp_v1 & 0x20) {
        var_f0 = D_003DF448;
    }
    return var_f0;
}

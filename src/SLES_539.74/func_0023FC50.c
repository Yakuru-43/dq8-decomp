// range: 0x23FC50 0x23FCB0
#include "common.h"

f32 func_0013BCA0(f32);

s32 func_0023FC50(char *arg0, s32 arg1) {
    f32 temp_f0;

    if (arg1 != 1) {
        return 0;
    }
    temp_f0 = func_0013BCA0(*(f32 *)(*(char **)(arg0 + 4) + 4));
    if (*(s32 *)arg0 == 3) {
        *(f32 *)(*(char **)(arg0 + 4) + 4) = temp_f0;
    }
    return 1;
}

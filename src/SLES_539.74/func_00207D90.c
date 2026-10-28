// range: 0x207D90 0x207DE0
#include "common.h"

f32 func_00207D90(char *arg0) {
    f32 temp_f1;
    f32 var_f0;

    if (arg0 != NULL) {
        var_f0 = 0.0f;
        temp_f1 = (f32) *(s32 *)arg0;
        if (temp_f1 == 0.0f) {
            return var_f0;
        }
        var_f0 = (f32) *(s32 *)(arg0 + 4) / temp_f1;
        return var_f0;
    }
    return 0.0f;
}

// range: 0x176010 0x176080
#include "common.h"

extern f32 D_00408630[];

void func_00176010(s32 arg0, f32 arg1) {
    f32 val = arg1;
    if (arg0 >= 0 && arg0 < 0x10) {
        if (val < 0.0f) {
            val = 0.0f;
        }
        if (val > 1.0f) {
            val = 1.0f;
        }
        D_00408630[arg0] = val;
    }
}

// range: 0x2036F0 0x203740
#include "common.h"

s32 func_00201DB0(s32);
s32 func_002067E0(s32, s32, s32);

s32 func_002036F0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_00201DB0(arg0);
    if (temp_v0 != 0) {
        return func_002067E0(temp_v0, arg1, arg2);
    }
    return 0;
}

// range: 0x364100 0x364130
#include "common.h"

s32 func_00364130(s32, s32, s32);

s32 func_00364100(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        return func_00364130(arg0, arg1, 0);
    }
    return 0;
}

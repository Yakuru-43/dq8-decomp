// range: 0x2FF0D0 0x2FF0F0
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

s32 func_002FF0D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return arg0 + (arg1 - arg0) * arg2 / arg3;
}

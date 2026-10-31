// range: 0x3866A0 0x3866C0
#include "common.h"

s32 func_003866A0(s32 arg0, s32 arg1, s32 arg2) {
    return *(s32 *) (arg0 + (arg1 * 0x10) + (arg2 * 4));
}

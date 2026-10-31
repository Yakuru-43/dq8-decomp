// range: 0x17ACB0 0x17AD30
#include "common.h"

extern s32 D_003E046C;

s32 func_0017ACB0(s32 arg0) {
    s32 d;
    if (arg0 == 0) {
        d = D_003E046C;
        if ((u32)(d - 2) < 2U) {
            return 1;
        }
    }
    if (arg0 == 1) {
        d = D_003E046C;
        if (d == 2 || d == 3 || d == 10) {
            return 1;
        }
    }
    return 0;
}

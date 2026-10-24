// range: 0x210F80 0x210FC0
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

extern s32 D_003E0964;

void func_00210F80(void) {
    D_003E0964 = D_003E0964 + 1;
    if (D_003E0964 / 300 >= 8) {
        D_003E0964 = 0;
    }
}

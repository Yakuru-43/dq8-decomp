// range: 0x301200 0x301250
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

extern s32 func_00132D38(void);

s32 func_00301200(char *arg0) {
    u8 *counter = *(u8 **)(arg0 + 0x10);
    s32 divisor;

    divisor = counter[1];
    if (divisor < 1) {
        divisor = 1;
    }
    return func_00132D38() % divisor + 1;
}

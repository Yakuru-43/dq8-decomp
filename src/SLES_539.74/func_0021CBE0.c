// range: 0x21CBE0 0x21CC10
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

s32 func_0021CBE0(void *arg0) {
    return (M2C_FIELD(arg0, s32 *, 0xC) - 4) / 13 - 1;
}

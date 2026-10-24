// range: 0x3076E0 0x307730
#include "common.h"

s32 func_001814D0(void);

void func_003076E0(s32 arg0) {
    s32 work = func_001814D0();

    if (arg0 != 0) {
        M2C_FIELD(work, s32 *, 0x50) |= 0x04000000;
    } else {
        M2C_FIELD(work, s32 *, 0x50) &= ~0x04000000;
    }
}

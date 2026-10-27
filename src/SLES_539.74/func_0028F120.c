// range: 0x28F120 0x28F160
#include "common.h"

extern void *D_003E13D0;

void func_00353E00(void *arg0);

s32 func_0028F120(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x4E4) = 0;
    M2C_FIELD(arg0, s32 *, 0x4E8) = 0;
    if (D_003E13D0 != NULL) {
        func_00353E00(D_003E13D0);
    }
    return 0;
}

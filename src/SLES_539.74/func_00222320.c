// range: 0x222320 0x222360
#include "common.h"

extern void func_00222360(void *arg0, s32 arg1);

void func_00222320(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x1F2B) = arg1;
    if (arg1 == 1) {
        func_00222360(arg0, 1);
    } else {
        func_00222360(arg0, 0);
    }
}

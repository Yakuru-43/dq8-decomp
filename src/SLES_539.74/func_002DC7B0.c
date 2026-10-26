// range: 0x2DC7B0 0x2DC7E0
#include "common.h"

extern void func_002DC7E0(s32, s32, s32, s32, ...);

s32 func_002DC7B0(s32 arg0, s32 arg1, char *arg2, s32 arg3) {
    func_002DC7E0(arg0, arg1, M2C_FIELD(arg2, s32 *, 0x2C), arg3, 2);
    return 0;
}

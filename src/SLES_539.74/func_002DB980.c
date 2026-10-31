// range: 0x2DB980 0x2DB9B0
#include "common.h"

extern void func_002DB9B0(s32, s32, s32, s32, ...);

s32 func_002DB980(s32 arg0, s32 arg1, char *arg2, s32 arg3) {
    func_002DB9B0(arg0, arg1, M2C_FIELD(arg2, s8 *, 0x2A),
                  M2C_FIELD(arg2, s32 *, 0x2C), arg3);
    return 0;
}

// range: 0x203F90 0x203FD0
#include "common.h"

s32 func_00203DF0(s32, s32);
s32 func_00203FD0(void);

s32 func_00203F90(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 4) {
        return func_00203DF0(arg0, arg2);
    }
    return 0xC - func_00203FD0();
}

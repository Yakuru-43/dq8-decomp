// range: 0x30C9A0 0x30C9F0
#include "common.h"

u32 func_002C17F0(s32);                       /* extern */
M2C_UNK func_00356910(s32, s32);              /* extern */

void func_0030C9A0(s32 arg0) {
    u32 work = func_002C17F0(arg0);
    if (work != 0) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}

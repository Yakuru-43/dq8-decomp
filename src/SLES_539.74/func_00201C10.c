// range: 0x201C10 0x201C90
#include "common.h"

s32 func_00181420(void);
void func_00205FB0(s32, s32, s32);

s32 func_00201C10(s32 arg0) {
    s32 buf[4];
    s32 i;

    if (arg0 < 0 || arg0 >= 4) {
        return arg0;
    }
    func_00205FB0(func_00181420(), (s32)buf, 0);
    for (i = 0; i < 4; i++) {
        if (buf[i] == arg0) {
            return i;
        }
    }
    return -1;
}

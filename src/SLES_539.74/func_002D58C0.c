// range: 0x2D58C0 0x2D5900
#include "common.h"

char *func_002D7880(s32, s32, s32);

void func_002D58C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *temp_v0;

    temp_v0 = func_002D7880(arg0, arg1, arg3);
    if (temp_v0 != NULL) {
        *(s32 *)(temp_v0 + 4) = arg2;
    }
}

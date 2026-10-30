// range: 0x358F70 0x358FD0
#include "common.h"

extern s32 *func_00359CF0(s8 *, s32);

void func_00358F70(s8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_v0;
    s32 var_v1;

    temp_v0 = func_00359CF0(arg0, arg1);
    if (temp_v0 != NULL) {
        if (arg3 != 0) {
            var_v1 = *(s32 *)((char *)temp_v0 + 0x1C) | arg2;
            *(s32 *)((char *)temp_v0 + 0x1C) = var_v1;
        } else {
            var_v1 = *(s32 *)((char *)temp_v0 + 0x1C) & ~arg2;
            *(s32 *)((char *)temp_v0 + 0x1C) = var_v1;
        }
    }
}

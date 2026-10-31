// range: 0x204BF0 0x204C60
#include "common.h"

s32 func_002061F0(char *, char *);
s32 func_00204E20(char *, char *);
s32 func_00207AA0(char *, s32, s32);

s32 func_00204BF0(char *arg0, char *arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_002061F0(arg0, arg1);
    if (!temp_v0) {
        return 0;
    }
    return func_00207AA0((char *)temp_v0, arg2, func_00204E20(arg0, arg1));
}

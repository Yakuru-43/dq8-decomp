// range: 0x1C0820 0x1C0890
#include "common.h"

char *func_00181420(char *);
s32 func_00203B10(char *, s32);

s32 func_001C0820(char *arg0) {
    char *temp_v0;
    s32 temp_v0_2;
    s32 a1;

    temp_v0 = func_00181420(arg0);
    if (temp_v0 == NULL) {
        return 0;
    }
    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(f32 *)&arg0[4];
    } else {
        a1 = *(s32 *)&arg0[4];
    }
    temp_v0_2 = func_00203B10(temp_v0, a1);
    if (*(s32 *)&arg0[8] == 3) {
        *(s32 *)(*(char **)&arg0[0xC] + 4) = temp_v0_2;
    }
    return 1;
}

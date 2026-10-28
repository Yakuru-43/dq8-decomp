// range: 0x1BA970 0x1BA9F0
#include "common.h"

char *func_00168150(void);
s32 func_0016E2E0(s32, s32);

s32 func_001BA970(char *arg0, s32 arg1) {
    char *temp_v0;
    s32 temp_v0_2;
    s32 a1;

    if (arg1 != 2) {
        return 0;
    }
    temp_v0 = func_00168150();
    if (M2C_FIELD(arg0, s32 *, 0) == 1) {
        a1 = (s32)*(f32 *)&arg0[4];
    } else {
        a1 = M2C_FIELD(arg0, s32 *, 4);
    }
    temp_v0_2 = func_0016E2E0((s32)temp_v0, a1);
    if (M2C_FIELD(arg0, s32 *, 8) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, char **, 0xC), s32 *, 4) = temp_v0_2;
    }
    return 1;
}

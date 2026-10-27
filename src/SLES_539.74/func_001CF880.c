// range: 0x1CF880 0x1CF910
#include "common.h"

char *func_001814D0(void);
s16 func_00308490(char *, s32, s16);

s32 func_001CF880(char *arg0) {
    s32 a1;
    s32 a2;
    char *temp_v0;

    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(float *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    if (*(s32 *)(arg0 + 8) == 1) {
        a2 = (s32)*(float *)(arg0 + 0xC);
    } else {
        a2 = *(s32 *)(arg0 + 0xC);
    }
    temp_v0 = func_001814D0();
    if (temp_v0 == NULL) {
        return 0;
    }
    func_00308490(temp_v0, a1, (s16)a2);
    return 1;
}

// range: 0x1CF9A0 0x1CFA20
#include "common.h"

char *func_001814D0(void);
s32 func_00308550(char *, s32, s32);

s32 func_001CF9A0(char *arg0) {
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
    func_00308550(temp_v0, a1, a2);
    return 1;
}

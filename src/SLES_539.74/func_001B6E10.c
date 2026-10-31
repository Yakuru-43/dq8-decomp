// range: 0x1B6E10 0x1B6E90
#include "common.h"

char *func_001814D0(void);
void func_003081D0(char *, s32, s32);

s32 func_001B6E10(char *arg0) {
    s32 a1;
    s32 a2;

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
    func_003081D0(func_001814D0(), a1, a2);
    return 1;
}

// range: 0x27EF50 0x27EFD0
#include "common.h"

void func_00134750(char *, char *, s32);
extern char *D_003E0DD4;
extern char *D_003E0DD8;
extern char *D_003E0DDC;

s32 func_0027EF50(s32 arg0, s128 *arg1, char *arg2) {
    if (D_003E0DD4 == NULL) {
        return 0;
    }
    if (arg0 < 0 || (u32)arg0 >= (u32)*(u32 *)(D_003E0DD4 + 0x24)) {
        *arg1 = 0;
        return 0;
    }
    *arg1 = *(s128 *)(D_003E0DD8 + (arg0 << 4));
    if (arg2 != NULL) {
        func_00134750(arg2, D_003E0DDC + (arg0 << 3), 8);
    }
    return 1;
}

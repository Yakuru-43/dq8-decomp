// range: 0x264C20 0x264CE0
#include "common.h"

extern void func_001340C0(s32, char *);
extern char *func_001FFC30(s32);

s32 func_00264C20(s32 arg0, s32 arg1, s32 arg2) {
    char *a1;

    if (arg1 < 0 || arg1 >= 0x11) {
        return 0;
    }
    a1 = 0;
    if (arg2 == 0) {
        a1 = func_001FFC30(arg1 + 0x1AE);
    }
    if (arg2 == 1) {
        a1 = func_001FFC30(arg1 + 0x190);
    }
    if (arg2 == 2) {
        a1 = func_001FFC30(arg1 + 0x1CC);
    }
    if (a1 != 0) {
        func_001340C0(arg0, a1);
    }
    return 1;
}

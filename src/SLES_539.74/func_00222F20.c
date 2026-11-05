// range: 0x222F20 0x222FC0
#include "common.h"

extern void func_0022A6F0(char *);
extern void func_001340C0(char *, void *);
extern s32 func_0022A880(s32 value);
extern void func_00133CB8(char *dst, char *src);

extern char D_003C8260[];
extern char D_003C81E0[];

/* Pads arg0 with count-two strings while formatting arg1 into a stack buffer. */
s32 func_00222F20(char *arg0, s32 arg1, s32 arg2) {
    char buf[0x11];
    s32 n;
    s32 i;

    func_0022A6F0(buf);
    func_001340C0(arg0, D_003C8260);
    n = (3 - func_0022A880(arg1)) * 2;
    if (arg2 != 0) {
        for (i = 0; i < n; i = i + 1) {
            func_00133CB8(arg0, D_003C81E0);
        }
    }
    func_00133CB8(arg0, buf);
    return 0;
}

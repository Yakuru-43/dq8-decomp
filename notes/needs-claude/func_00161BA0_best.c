// Best draft for func_00161BA0 (NOT matched, kept out of src/).
// range: 0x00161BA0 0x00161C70
#include "common.h"

extern u32 func_001341D8(char *);
extern char *func_001340C0(char *, char *);

void func_00161BA0(char *arg0, char *arg1, char *arg2) {
    char *dst;
    char *src;
    s32 i;
    s32 n;

    i = func_001341D8(arg0) - 1;
    while (i >= 0) {
        if (arg0[i] == '/') {
            break;
        }
        i--;
    }
    if (i == 0) {
        func_001340C0(arg2, arg0);
        *arg1 = 0;
        return;
    }
    dst = arg1;
    src = arg0;
    for (n = 0; n <= i; n++) {
        *dst++ = *src++;
    }
    func_001340C0(arg2, arg0 + i + 1);
    *dst = 0;
}

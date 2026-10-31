// range: 0x36F700 0x36F740
#include "common.h"

void func_001340C0(char *, char *);
char *func_0036F740(s32);

s32 func_0036F700(char *arg0, s32 arg1) {
    char *temp_v0;

    temp_v0 = func_0036F740(arg1);
    if (temp_v0 != NULL) {
        func_001340C0(arg0, temp_v0);
    }
    return 1;
}

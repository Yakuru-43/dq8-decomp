// range: 0x36F0B0 0x36F0F0
#include "common.h"

void func_001340C0(char *, char *);
void func_0036F0F0(char *, char *);

void func_0036F0B0(char *arg0) {
    char sp20[0x100];

    if (arg0 != NULL) {
        func_0036F0F0(arg0, sp20);
        func_001340C0(arg0, sp20);
    }
}

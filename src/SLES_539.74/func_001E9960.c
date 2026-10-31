// range: 0x1E9960 0x1E99B0
#include "common.h"

void func_001E9A30(char *, char *);
int func_0013C5E0();

void func_001E9960(char *arg0, void *arg1, void *arg2) {
    char sp30[0x40];

    func_001E9A30(arg0, sp30);
    func_0013C5E0(arg1, sp30, arg2);
}

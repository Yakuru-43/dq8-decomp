// range: 0x1E99B0 0x1E9A00
#include "common.h"

void func_001E9A30(char *, char *);
int func_0013C610();

void func_001E99B0(char *arg0, void *arg1, void *arg2) {
    char sp30[0x40];

    func_001E9A30(arg0, sp30);
    func_0013C610(arg1, sp30, arg2);
}

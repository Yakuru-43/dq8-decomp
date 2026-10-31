// range: 0x167830 0x167850
#include "common.h"

void func_0013B7B0(char *, char *, char *);

void func_00167830(char *arg0, s128 *arg1) {
    s128 tmp = *arg1;
    *(s128 *)(arg0 + 0xD0) = tmp;
    func_0013B7B0(arg0 + 0xE0, arg0 + 0xD0, arg0 + 0x120);
}

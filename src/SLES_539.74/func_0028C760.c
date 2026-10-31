// range: 0x28C760 0x28C770
#include "common.h"

extern void func_0013B720(void *arg0);

void func_0028C760(char *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x120) = arg1;
    func_0013B720(arg0 + 0x130);
}

// range: 0x276E70 0x276EB0
#include "common.h"

extern void func_0013B6D0(void *, void *);

void func_00276E70(char *arg0, char *arg1) {
    f32 t;

    t = *(f32 *)(arg1 + 0xC);
    func_0013B6D0(arg1, arg0 + 0x40);
    *(f32 *)(arg1 + 0xC) = t;
}

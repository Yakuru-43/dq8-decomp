// range: 0x29C600 0x29C640
#include "common.h"

extern void func_00131188(void *, s32, s32);

void func_0029C600(s32 *arg0) {
    func_00131188(arg0, 0, 0x2C);
    arg0[0] = -1;
    arg0[3] = -1;
}

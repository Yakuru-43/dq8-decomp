// range: 0x220750 0x2207A0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002F7430(char *, s8);
void func_00220750(char *arg0, s32 arg1) {
    if (arg1 != 0) {
        func_002F7430(arg0, 0);
        M2C_FIELD(arg0, s8 *, 0x11D4) = 1;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x11D4) = 0;
    func_002F7430(arg0, 1);
}

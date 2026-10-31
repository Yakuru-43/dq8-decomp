// range: 0x2BE9F0 0x2BEA40
#include "common.h"

char *func_001814D0(s32 arg0);
s32 func_003084D0(char *, s32);
void func_002BEA40(s32, s32, u8);

void func_002BE9F0(s32 arg0) {
    func_002BEA40(arg0, 0, !func_003084D0(func_001814D0(arg0), 0x3A));
}

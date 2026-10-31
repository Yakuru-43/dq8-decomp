// range: 0x350880 0x350890
#include "common.h"

void func_00350170(char *, s32);

void func_00350880(char *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 4) = arg1;
    func_00350170(arg0 + 12, arg2);
}

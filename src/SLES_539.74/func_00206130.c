// range: 0x206130 0x2061A0
#include "common.h"

void func_002060F0(void *, s32);

void func_00206130(void *arg0, s32 arg1) {
    *(s16 *)((char *)arg0 + 0x14) = 0;
    func_002060F0(arg0, 0);
    if (arg1 == 1) {
        func_002060F0(arg0, 1);
        func_002060F0(arg0, 2);
        func_002060F0(arg0, 3);
    }
}

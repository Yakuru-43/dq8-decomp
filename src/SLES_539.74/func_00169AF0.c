// range: 0x169AF0 0x169B50
#include "common.h"

void func_001007A0(void *);
void func_00107D30(void *, s32);

void *func_00169AF0(void *arg0, s64 arg1) {
    if (arg0 != NULL) {
        func_00107D30(arg0, -1);
        if (((s64)(arg1 << 0x30) >> 0x30) > 0) {
            func_001007A0(arg0);
        }
    }
    return arg0;
}

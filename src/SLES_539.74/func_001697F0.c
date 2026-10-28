// range: 0x1697F0 0x169850
#include "common.h"

void func_001007A0(void *);
void func_00107D30(void *, s32);

void *func_001697F0(void *arg0, s64 arg1) {
    if (arg0 != NULL) {
        func_00107D30(arg0, -1);
        if (((s64)(arg1 << 0x30) >> 0x30) > 0) {
            func_001007A0(arg0);
        }
    }
    return arg0;
}

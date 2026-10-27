// range: 0x16A0F0 0x16A150
#include "common.h"

void func_00107D30(void *, s32);
void func_001007A0(void *);

void *func_0016A0F0(void *arg0, s64 arg1) {
    if (arg0 != NULL) {
        func_00107D30(arg0, -1);
        if ((s16)arg1 > 0) {
            func_001007A0(arg0);
        }
    }
    return arg0;
}

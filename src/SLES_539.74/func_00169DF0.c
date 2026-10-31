// range: 0x169DF0 0x169E50
#include "common.h"

void func_001007A0(void *);
void func_00107D30(void *, s32);

void *func_00169DF0(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        func_00107D30(arg0, -1);
        if (arg1 > 0) {
            func_001007A0(arg0);
        }
    }
    return arg0;
}

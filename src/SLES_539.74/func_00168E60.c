// range: 0x168E60 0x168ED0
#include "common.h"

void func_001007A0(void *);
void func_00169BB0(void *, s32);

void *func_00168E60(void *arg0, s64 arg1) {
    s32 temp_a1;

    if (arg0 != NULL) {
        if (arg0 != NULL) {
            temp_a1 = *(s32 *)((char *)arg0 + 4);
            if (temp_a1 != 0) {
                func_00169BB0(arg0, temp_a1);
            }
        }
        if (((s64)(arg1 << 0x30) >> 0x30) > 0) {
            func_001007A0(arg0);
        }
    }
    return arg0;
}

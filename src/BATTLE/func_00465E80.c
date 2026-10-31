// range: 0x465E80 0x465ED0
#include "common.h"

void func_00467070(s8 *, s8);

void func_00465E80(s8 *base, s32 idx, s8 value) {
    if (idx >= 0) {
        if (idx < 0x18) {
            func_00467070(base + idx * 608, value);
        }
    }
}

// range: 0x465F20 0x465F70
#include "common.h"

void func_00465F70(s8 *, s8);

void func_00465F20(s8 *base, s32 idx, s8 value) {
    if (idx >= 0) {
        if (idx < 0x18) {
            func_00465F70(base + idx * 608, value);
        }
    }
}

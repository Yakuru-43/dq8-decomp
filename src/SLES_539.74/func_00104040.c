// range: 0x104040 0x104050
// Clears the value/count pair (value -1, count 0).
#include "common.h"

void func_00104040(s64 *slot) {
    *slot = -1;
    *(s32 *)(slot + 1) = 0;
}

// range: 0x104050 0x104060
// Clears the value/count pair (value -1, count 0).
#include "common.h"

void func_00104050(s64 *slot) {
    *slot = -1;
    *(s32 *)(slot + 1) = 0;
}

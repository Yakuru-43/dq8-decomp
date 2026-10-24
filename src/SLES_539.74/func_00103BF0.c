// range: 0x103BF0 0x103C00
// Vtable stub: clears the value/count pair.
#include "common.h"

void func_00103BF0(s64 *slot) {
    *slot = -1;
    *(s32 *)(slot + 1) = 0;
}

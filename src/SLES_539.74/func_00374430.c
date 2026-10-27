// range: 0x374430 0x374450
#include "common.h"

extern M2C_UNK D_003AEFA8 __attribute__((section(".data")));   /* extern */

s8 func_00374430(s32 arg0) {
    return *((s8 *)&D_003AEFA8 + arg0);
}

// range: 0x2C16E0 0x2C1700
#include "common.h"

extern M2C_UNK D_003AA420 __attribute__((section(".data")));   /* extern */

s32 func_002C16E0(s32 arg0) {
    return *((s32 *)&D_003AA420 + arg0);
}

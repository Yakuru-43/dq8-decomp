// range: 0x2C09E0 0x2C0A00
#include "common.h"

extern M2C_UNK D_003CCEC8 __attribute__((section(".data")));   /* extern */

s8 func_002C09E0(s32 arg0) {
    return *((s8 *)&D_003CCEC8 + arg0);
}

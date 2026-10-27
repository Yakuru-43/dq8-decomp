// range: 0x193500 0x193520
#include "common.h"

extern M2C_UNK D_003A1A28 __attribute__((section(".data")));   /* extern */

s32 func_00193500(s32 arg0) {
    return *((s32 *)&D_003A1A28 + arg0);
}

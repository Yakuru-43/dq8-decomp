// range: 0x23A200 0x23A230
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *);                     /* extern */
extern M2C_UNK D_003C87A0 __attribute__((section(".data")));

s32 func_0023A200(void) {
    DebugPrintf(&D_003C87A0);
    return 0;
}

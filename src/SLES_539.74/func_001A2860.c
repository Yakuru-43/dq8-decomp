// range: 0x1A2860 0x1A2890
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001D59C0(M2C_UNK *, s32);                  /* extern */
extern M2C_UNK D_00410EE0 __attribute__((section(".data")));

s32 func_001A2860(s32 arg0) {
    return func_001D59C0(&D_00410EE0, arg0) != 0;
}

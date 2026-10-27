// range: 0x46DD10 0x46DD40
// auto: m2c draft, verified byte-exact
#include "common.h"

u32 func_0046DD40();                                /* extern */

s32 func_0046DD10(void) {
    return (func_0046DD40() >= 2U) & 0xFF;
}

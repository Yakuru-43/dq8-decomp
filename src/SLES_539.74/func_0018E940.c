// range: 0x18E940 0x18E970
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0018F090();                                /* extern */

s32 func_0018E940(void) {
    return (func_0018F090() & 1) != 0;
}

// range: 0x370F60 0x370F90
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00370F90();                                /* extern */

s32 func_00370F60(s32 arg0, s32 arg1) {
    return (arg1 & func_00370F90()) != 0;
}

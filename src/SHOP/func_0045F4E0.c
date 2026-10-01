// range: 0x45F4E0 0x45F520
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_181420();                                  /* extern */
s32 func_205050(s32, s32, M2C_UNK);                 /* extern */

s32 func_0045F4E0(s32 arg0) {
    return (func_205050(func_181420(), arg0, 1) >= 1) & 0xFF;
}

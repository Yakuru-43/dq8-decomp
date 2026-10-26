// range: 0x222EF0 0x222F20
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 func_00370500(void);

s32 func_00222EF0(void) {
    return func_00370500() == 0 ? 0xF : 0x10;
}

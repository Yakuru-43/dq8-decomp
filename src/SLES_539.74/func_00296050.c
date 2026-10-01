// range: 0x296050 0x2960A0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00296BB0(void *);                      /* extern */
s32 func_00296F60(s32);                             /* extern */

s32 func_00296050(void *arg0) {
    if (!(func_00296F60(M2C_FIELD(arg0, s32 *, 0x58C)) & 0x800)) {
        func_00296BB0(arg0);
        return 1;
    }
    return 0;
}

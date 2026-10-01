// range: 0x2944D0 0x294520
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00296BB0(void *);                      /* extern */
s32 func_00297050(s32);                             /* extern */

s32 func_002944D0(void *arg0) {
    if (func_00297050(M2C_FIELD(arg0, s32 *, 0x58C)) <= 0) {
        func_00296BB0(arg0);
        return 1;
    }
    return 0;
}

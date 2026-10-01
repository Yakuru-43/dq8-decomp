// range: 0x18AB90 0x18ABD0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0018ACA0();                                /* extern */
M2C_UNK func_0019B030();                    /* extern */

void func_0018AB90(char *arg0, s32 arg1) {
    func_0019B030(arg0 + 0x68E0, arg1 * func_0018ACA0());
    M2C_FIELD(arg0, s16 *, 0x6930) = 0;
}

// range: 0x3762B0 0x376300
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001813D0();                              /* extern */

void func_003762B0(s32 *arg0, s32 *arg1) {
    *arg0 = M2C_FIELD(func_001813D0(), s32 *, 0x1C);
    *arg1 = M2C_FIELD(func_001813D0(), s32 *, 0x20);
}

// range: 0x307750 0x307780
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001814D0();                              /* extern */

void func_00307750(s16 arg0) {
    M2C_FIELD(func_001814D0(), s16 *, 0x172) = arg0;
}

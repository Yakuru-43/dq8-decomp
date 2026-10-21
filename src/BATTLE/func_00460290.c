// range: 0x460290 0x4602D0
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00460500();                              /* extern */

void func_00460290(void) {
    char *temp_v0;

    temp_v0 = func_00460500();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s16 *, 0) = -1;
        M2C_FIELD(temp_v0, s16 *, 0xA) = 0;
        M2C_FIELD(temp_v0, s16 *, 8) = -1;
    }
}

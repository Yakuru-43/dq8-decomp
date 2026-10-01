// range: 0x2D70E0 0x2D7120
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_002D4150();                              /* extern */

void func_002D70E0(f32 fparg0, f32 fparg1) {
    char *temp_v0;

    temp_v0 = func_002D4150();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 0x20) = fparg0;
        M2C_FIELD(temp_v0, f32 *, 0x24) = fparg1;
    }
}

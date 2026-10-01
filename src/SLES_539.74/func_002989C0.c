// range: 0x2989C0 0x298A00
// auto: m2c, verified byte-exact
#include "common.h"

void *func_002988C0();                              /* extern */

u8 func_002989C0(void) {
    u8 var_s0;
    void *temp_v0;

    var_s0 = 0;
    temp_v0 = func_002988C0();
    if (temp_v0 != NULL) {
        var_s0 = M2C_FIELD(temp_v0, u8 *, 1);
    }
    return var_s0;
}

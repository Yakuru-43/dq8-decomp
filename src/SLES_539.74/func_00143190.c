// range: 0x143190 0x1431B0
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_00143190(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0xF20);
    if (temp_v0 != NULL) {
        return M2C_FIELD(temp_v0, f32 *, 0x14);
    }
    return 0.0f;
}

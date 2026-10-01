// range: 0x35D930 0x35D970
// auto: m2c, verified byte-exact
#include "common.h"

u8 func_0035D930(void *arg0, s32 arg1) {
    u8 var_v0;
    void *temp_v1;

    var_v0 = M2C_FIELD(arg0, u8 *, 0xA0);
    if ((arg1 != 0) && (M2C_FIELD(arg0, s32 *, 0xE0) > 0)) {
        temp_v1 = M2C_FIELD(arg0, void **, 0x368);
        if ((temp_v1 != NULL) && !(M2C_FIELD(temp_v1, s32 *, 0x20) & 0x100000)) {
            var_v0 = 0;
        }
    }
    return var_v0;
}

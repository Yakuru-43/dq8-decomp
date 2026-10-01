// range: 0x3263E0 0x326420
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00320FE0(s32, s32);                    /* extern */

s32 func_003263E0(void *arg0) {
    void *var_v0;

    var_v0 = M2C_FIELD(arg0, void **, 8);
    if (var_v0 == NULL) {
        var_v0 = NULL;
    }
    if (var_v0 == NULL) {
        return -1;
    }
    func_00320FE0(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(M2C_FIELD(M2C_FIELD(var_v0, void **, 0x2C), void **, 8), s32 *, 0x70));
    return 0;
}

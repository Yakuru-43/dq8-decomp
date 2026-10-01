// range: 0x324640 0x324680
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00320FE0(s32, s32);                    /* extern */

s32 func_00324640(void *arg0) {
    void *var_v0;

    var_v0 = M2C_FIELD(arg0, void **, 8);
    if (var_v0 == NULL) {
        var_v0 = NULL;
    }
    if (var_v0 == NULL) {
        return -1;
    }
    func_00320FE0(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(var_v0, s32 *, 0x24));
    return 0;
}

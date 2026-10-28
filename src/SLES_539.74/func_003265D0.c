// range: 0x3265D0 0x326630
#include "common.h"

M2C_UNK func_00320FE0(s32, s32);                    /* extern */
M2C_UNK func_00340900(s32);                         /* extern */
s32 func_0031E410(void *);                          /* extern */

s32 func_003265D0(void *arg0) {
    void *var_v0;

    var_v0 = M2C_FIELD(arg0, void **, 8);
    var_v0 = var_v0 != NULL ? var_v0 : NULL;
    if (var_v0 == NULL) {
        return -1;
    }
    func_00320FE0(M2C_FIELD(arg0, s32 *, 4), func_00340900(func_0031E410(M2C_FIELD(M2C_FIELD(var_v0, void **, 0x2C), void **, 8))));
    return 0;
}

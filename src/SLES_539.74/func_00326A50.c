// range: 0x326A50 0x326AC0
#include "common.h"

M2C_UNK func_00320FE0(s32, s32);                    /* extern */
s32 func_00340E50(s32);                              /* extern */
s32 func_0031E440(void *);                           /* extern */

s32 func_00326A50(void *arg0) {
    void *var_v0;

    var_v0 = M2C_FIELD(arg0, void **, 8);
    var_v0 = var_v0 != NULL ? var_v0 : NULL;
    if (var_v0 == NULL) {
        return -1;
    }
    func_00320FE0(M2C_FIELD(arg0, s32 *, 4), func_00340E50(func_0031E440(M2C_FIELD(M2C_FIELD(var_v0, void **, 0x2C), void **, 8))) == 0x3E8);
    return 0;
}

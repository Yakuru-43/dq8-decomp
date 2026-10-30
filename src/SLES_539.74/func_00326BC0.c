// range: 0x326BC0 0x326C30
#include "common.h"

M2C_UNK func_00320FE0(s32, s32);                    /* extern */
s32 func_00340BC0(s32, s32);                        /* extern */
s32 func_0031E440(void *);                          /* extern */

s32 func_00326BC0(void *arg0) {
    void *var_v0;

    var_v0 = M2C_FIELD(arg0, void **, 8);
    var_v0 = var_v0 != NULL ? var_v0 : NULL;
    if (var_v0 == NULL) {
        return -1;
    }
    func_00320FE0(M2C_FIELD(arg0, s32 *, 4), func_00340BC0(func_0031E440(M2C_FIELD(M2C_FIELD(var_v0, void **, 0x2C), void **, 8)), 0x80));
    return 0;
}

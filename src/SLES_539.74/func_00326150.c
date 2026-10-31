// range: 0x326150 0x3261B0
#include "common.h"

M2C_UNK func_00320FE0(s32, s32);                    /* extern */
void *func_0031E420(void *);                         /* extern */

s32 func_00326150(void *arg0) {
    void *var_v0;
    void *var_v1;

    var_v0 = M2C_FIELD(arg0, void **, 8);
    var_v0 = var_v0 != NULL ? var_v0 : NULL;
    if (var_v0 == NULL) {
        return -1;
    }
    var_v1 = func_0031E420(M2C_FIELD(M2C_FIELD(var_v0, void **, 0x2C), void **, 8));
    func_00320FE0(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(var_v1, s32 *, 0x28));
    return 0;
}

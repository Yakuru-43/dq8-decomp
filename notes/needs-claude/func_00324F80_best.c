// range: 0x324F80 0x325010
#include "common.h"

s32 func_0031E440(void *);                           /* extern */
M2C_UNK func_00342160(s32);                          /* extern */
s32 func_00318150(s32, s32, s32);                    /* extern */
s32 func_00319F50(s32, s32, void *);                  /* extern */

s32 func_00324F80(void *arg0) {
    void *var_s0;
    s32 var_a2;
    s32 var_s1;
    s32 var_a1;
    s32 var_v0;

    var_s0 = M2C_FIELD(arg0, void **, 8);
    var_s0 = var_s0 != NULL ? var_s0 : NULL;
    if (var_s0 == NULL) {
        return -1;
    }
    var_v0 = func_0031E440(M2C_FIELD(M2C_FIELD(var_s0, void **, 0x2C), void **, 8));
    if (func_00342160(var_v0) != 0) {
        return 0;
    }
    var_s1 = M2C_FIELD(var_s0, s32 *, 0x28);
    var_a2 = M2C_FIELD(var_s0, s32 *, 0x2C);
    var_a1 = M2C_FIELD(var_s0, s32 *, 0x30);
    var_s0 = M2C_FIELD(var_a2, void **, 8);
    if (var_a1 == 0) {
        return -1;
    }
    var_v0 = func_00318150(var_s1, var_a1, var_a2);
    return func_00319F50(var_s1, var_v0, var_s0);
}

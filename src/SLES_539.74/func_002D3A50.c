// range: 0x2D3A50 0x2D3AD0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002D39C0(void *, s32, void *);         /* extern */
s32 func_002D4150(void *, s32);                     /* extern */
void *func_002DDEF0(void *);                        /* extern */

s32 func_002D3A50(void *arg0) {
    s32 temp_v0_2;
    void *temp_v0;
    void *var_s0;

    var_s0 = M2C_FIELD(arg0, void **, 4);
    if (var_s0 == NULL) {
        return 0;
    }
    do {
        temp_v0 = M2C_FIELD(var_s0, void **, 0x88);
        if (temp_v0 != NULL) {
            temp_v0_2 = func_002D4150(arg0, M2C_FIELD(temp_v0, s32 *, 4));
            M2C_FIELD(M2C_FIELD(var_s0, void **, 0x88), s32 *, 0x74) = temp_v0_2;
            func_002D39C0(arg0, temp_v0_2, M2C_FIELD(var_s0, void **, 0x88));
        }
        var_s0 = func_002DDEF0(var_s0);
    } while (var_s0 != NULL);
    return 1;
}

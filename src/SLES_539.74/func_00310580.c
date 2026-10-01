// range: 0x310580 0x3105E0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00300CB0(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_003D0870 __attribute__((section(".data")));

void *func_00310580(void *arg0, s32 arg1) {
    void *temp_v0;
    void *var_a0;

    var_a0 = arg0;
    if (var_a0 != NULL) {
loop_1:
        var_a0 = M2C_FIELD(var_a0, void **, 0x18);
        if (var_a0 != NULL) {
            temp_v0 = M2C_FIELD(var_a0, void **, 0x1C);
            if ((temp_v0 == NULL) || (arg1 != M2C_FIELD(temp_v0, s16 *, 0x10))) {
                goto loop_1;
            }
        }
        return var_a0;
    }
    func_00300CB0(0, &D_003D0870, 0x48);
    return NULL;
}

// range: 0x264810 0x2648A0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_0014EB30(M2C_UNK, s32);                  /* extern */
M2C_UNK func_002F0B80(void *);                      /* extern */
M2C_UNK func_002F6430(void *, M2C_UNK);             /* extern */
M2C_UNK func_002F6640(void *, M2C_UNK);             /* extern */
void *func_002F6960(void *);                        /* extern */
M2C_UNK func_002F69B0(void *);                      /* extern */

void *func_00264810(s32 arg0, s32 arg1, M2C_UNK arg2) {
    void *var_s0;

    var_s0 = func_0014EB30(0x1F18, arg0);
    if (var_s0 != NULL) {
        var_s0 = func_002F6960(var_s0);
    }
    func_002F69B0(var_s0);
    func_002F6430(var_s0, 0);
    func_002F0B80(var_s0);
    M2C_FIELD(var_s0, s32 *, 0x1668) = arg1;
    func_002F6640(var_s0, arg2);
    return var_s0;
}

// range: 0x220870 0x220900
// auto: m2c, verified byte-exact
#include "common.h"

void *func_0014EB30(M2C_UNK, s32);                  /* extern */
s32 func_00167B10();                                /* extern */
s32 func_00167B20();                                /* extern */
M2C_UNK func_002224E0(void *, s32);                 /* extern */
M2C_UNK func_002224F0(void *);                      /* extern */
void *func_002226A0(void *);                        /* extern */
M2C_UNK func_002F6640(void *, M2C_UNK);             /* extern */

void *func_00220870(s32 arg0, M2C_UNK arg1) {
    void *var_s0;

    var_s0 = func_0014EB30(0x1F48, arg0);
    if (var_s0 != NULL) {
        var_s0 = func_002226A0(var_s0);
    }
    func_002224F0(var_s0);
    func_002F6640(var_s0, arg1);
    M2C_FIELD(var_s0, s32 *, 0x1668) = func_00167B10();
    func_002224E0(var_s0, func_00167B20());
    return var_s0;
}

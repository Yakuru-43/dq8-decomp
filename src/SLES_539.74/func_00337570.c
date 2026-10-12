// range: 0x337570 0x3375B0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00361450(s32);                         /* extern */

void func_00337570(char *arg0, s32 arg1) {

    if (!(arg1 != 0)) {
        return;
    }

    func_00361450(M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0x210) = (s32) (M2C_FIELD(arg0, s32 *, 0x210) - 1);
}

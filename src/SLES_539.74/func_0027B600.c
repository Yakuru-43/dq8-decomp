// range: 0x27B600 0x27B670
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002209F0(s32, M2C_UNK);                /* extern */
M2C_UNK func_00220F00(s32, s32);                    /* extern */
M2C_UNK func_00221310(s32, M2C_UNK);                /* extern */
M2C_UNK func_002E4DC0(s32, M2C_UNK, M2C_UNK);       /* extern */
extern s32 D_003E0868;

void func_0027B600(s32 arg0) {
    s32 temp_s0;

    temp_s0 = D_003E0868 + 0x5E78;
    func_002E4DC0(temp_s0, 0x186, 0xFE);
    func_002209F0(temp_s0, 0x5A);
    func_00221310(temp_s0, 1);
    func_00220F00(temp_s0, arg0);
}

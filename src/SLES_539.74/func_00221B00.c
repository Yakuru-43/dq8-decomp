// range: 0x221B00 0x221B60
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00221640(s32);                         /* extern */
M2C_UNK func_00221860(s32, M2C_UNK);                /* extern */
M2C_UNK func_00221B60(s32);                         /* extern */
M2C_UNK func_00221BC0();                            /* extern */
M2C_UNK func_00221C20(s32);                         /* extern */
M2C_UNK func_00221CF0(s32);                         /* extern */
M2C_UNK func_00222370(s32, M2C_UNK);                /* extern */

void func_00221B00(s32 arg0) {
    func_00221BC0();
    func_00221B60(arg0);
    func_00221C20(arg0);
    func_00221CF0(arg0);
    func_00221640(arg0);
    func_00222370(arg0, 0);
    func_00221860(arg0, 0);
}

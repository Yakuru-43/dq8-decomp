// range: 0x25F5A0 0x25F600
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001978C0();                            /* extern */
M2C_UNK func_00197A80(M2C_UNK);                     /* extern */
M2C_UNK func_00263CB0();                            /* extern */
M2C_UNK func_00263F50();                            /* extern */
M2C_UNK func_00350A20(s32);                         /* extern */
M2C_UNK func_00350E20(M2C_UNK);                     /* extern */

void func_0025F5A0(s32 arg0) {

    if (!(arg0 != 0)) {
        return;
    }

    func_00263F50();
    func_00263CB0();
    func_001978C0();
    func_00197A80(1);
    func_00350A20(arg0);
    func_00350E20(1);
}

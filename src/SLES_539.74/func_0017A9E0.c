// range: 0x17A9E0 0x17AA70
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00162BC0();                            /* extern */
s32 func_00162CA0();                                /* extern */
M2C_UNK func_001978C0();                            /* extern */
M2C_UNK func_00197A80(M2C_UNK);                     /* extern */
s32 func_001D7AA0();                                /* extern */
M2C_UNK func_001D7AB0(M2C_UNK);                     /* extern */
M2C_UNK func_00263830();                            /* extern */
M2C_UNK func_00350A20(s32);                         /* extern */
M2C_UNK func_00350E20(M2C_UNK);                     /* extern */
extern s8 D_003DFC0C;

void func_0017A9E0(s32 arg0) {
    if (func_00162CA0() != 0) {
        func_00162BC0();
    }
    func_001978C0();
    func_00197A80(1);
    func_00350E20(1);
    func_00350A20(arg0);
    D_003DFC0C = -1;
    if (func_001D7AA0() == 1) {
        func_001D7AB0(1);
        D_003DFC0C = 1;
    }
    func_00263830();
}

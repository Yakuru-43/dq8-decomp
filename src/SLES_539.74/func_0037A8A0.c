// range: 0x37A8A0 0x37A9B0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_002D45A0(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_002D45D0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0037AA00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_0037A8A0(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    if (arg0 != 0) {
        func_002D38E0(arg3, 0x409, 1, -1);
        func_002D38E0(arg3, 0x40A, 1, -1);
        func_0037AA00(1, arg1, arg2, arg3);
        func_002D45D0(arg3, 0x409, 5, 1);
        func_002D38E0(arg3, 0x18703, 0, -1);
        return;
    }
    func_002D38E0(arg3, 0x409, 0, -1);
    func_002D38E0(arg3, 0x40A, 0, -1);
    func_0037AA00(0, arg1, arg2, arg3);
    func_002D45A0(arg3, 0x409);
    func_002D38E0(arg3, 0x18703, 1, -1);
}

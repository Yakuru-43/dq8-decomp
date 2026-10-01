// range: 0x207550 0x2075B0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */

void func_00207550(M2C_UNK *arg0, M2C_UNK *arg1) {
    M2C_UNK sp3C;

    func_00130FD0(&sp3C, arg0, 4);
    func_00130FD0(arg0, arg1, 4);
    func_00130FD0(arg1, &sp3C, 4);
}

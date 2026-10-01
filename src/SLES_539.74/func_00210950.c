// range: 0x210950 0x2109E0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188();    /* extern */
M2C_UNK func_00206230();                         /* extern */
M2C_UNK func_002073D0();                         /* extern */
M2C_UNK func_0024BAD0();                         /* extern */
M2C_UNK func_002B21F0();                         /* extern */
M2C_UNK func_00305300();                         /* extern */
M2C_UNK func_003085F0();                      /* extern */
M2C_UNK func_00308760();                         /* extern */
M2C_UNK func_00308CB0();                         /* extern */

char *func_00210950(char *arg0) {
    func_00308CB0(arg0 + 0x4B0);
    func_002073D0(arg0 + 0xC10);
    func_00206230(arg0 + 0xA30);
    func_00305300(arg0 + 0x1740);
    func_002B21F0(arg0 + 0x58D0);
    func_0024BAD0(arg0 + 0x5A10);
    func_00308760(arg0 + 0x5C50);
    func_003085F0(arg0 + 0x40);
    func_00131188(arg0, 0, 0x40);
    M2C_FIELD(arg0, s32 *, 0x20) = 0x40;
    M2C_FIELD(arg0, s32 *, 0x24) = 0x5CA0;
    func_003085F0(arg0 + 0x40);
    return arg0;
}

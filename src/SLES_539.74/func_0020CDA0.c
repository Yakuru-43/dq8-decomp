// range: 0x20CDA0 0x20CE00
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001746D0(M2C_UNK, M2C_UNK, s32);       /* extern */
M2C_UNK func_00176500(M2C_UNK);                     /* extern */

void func_0020CDA0(char *arg0) {
    s32 var_a2;
    char *temp_v1;

    var_a2 = 0;
    M2C_FIELD(arg0, s32 *, 0x64D8) = -1;
    do {
        temp_v1 = arg0 + (var_a2 * 4);
        var_a2 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x64DC) = -1;
        M2C_FIELD(temp_v1, s32 *, 0x64E4) = -1;
    } while (var_a2 < 2);
    func_001746D0(8, -1, var_a2);
    func_00176500(8);
    M2C_FIELD(arg0, s32 *, 0x64F0) = 0;
}

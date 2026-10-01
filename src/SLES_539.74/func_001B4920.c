// range: 0x1B4920 0x1B4950
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002098D0(s32);                         /* extern */
M2C_UNK func_0020CDA0(s32);                         /* extern */
extern s32 D_003E0664;

s32 func_001B4920(void) {
    func_002098D0(D_003E0664);
    func_0020CDA0(D_003E0664);
    return 1;
}

// range: 0x2344C0 0x2344F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00234F60(s32);                         /* extern */

s32 func_002344C0(s32 arg0) {
    func_00234F60(arg0 + 0xC);
    return arg0;
}

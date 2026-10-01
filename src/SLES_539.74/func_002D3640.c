// range: 0x2D3640 0x2D3680
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002DDEE0(s32);                         /* extern */
M2C_UNK func_00375AC0(s32);                         /* extern */

s32 func_002D3640(s32 arg0) {
    func_00375AC0(arg0 + 0x30);
    func_002DDEE0(arg0);
    return arg0;
}

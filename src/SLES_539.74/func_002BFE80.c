// range: 0x2BFE80 0x2BFED0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002BD9D0(s32, M2C_UNK);                /* extern */
M2C_UNK func_002BFED0(s32, M2C_UNK);                /* extern */
M2C_UNK func_002C0060();                            /* extern */

void func_002BFE80(s32 arg0, M2C_UNK arg1) {
    func_002C0060();
    func_002BFED0(arg0, arg1);
    func_002BD9D0(arg0, arg1);
}

// range: 0x1EA850 0x1EA890
#include "common.h"

M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */

s8 *func_001EA850(s8 *arg0) {
    *(s32 *)(arg0 + 0x1BC) = 0;
    *(s32 *)(arg0 + 0x1B8) = 0;
    func_00131188((char *)arg0, 0, 0x1D0);
    return arg0;
}

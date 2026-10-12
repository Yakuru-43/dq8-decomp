// range: 0x340860 0x3408A0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */

s32 *func_00340860(s32 *arg0) {
    *arg0 = 0;
    func_00131188((char *) arg0 + 4, 0, 0x50);
    return arg0;
}

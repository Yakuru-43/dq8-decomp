// range: 0x16BC30 0x16BCA0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_0014DF80(char *);
M2C_UNK func_0016BA20();                            /* extern */

s32 func_0016BC30(s32 arg0, s32 arg1) {
    char *var_s0;

    if ((arg1 >= 0) && (arg1 < 0xE)) {
        var_s0= (char *) ( arg0 + (arg1 * 0x58) + 0x38);
    } else {
        var_s0 = NULL;
    }
    if (NULL == var_s0) {
        return -1;
    }
    func_0016BA20();
    func_0014DF80(var_s0);
    return 0;
}

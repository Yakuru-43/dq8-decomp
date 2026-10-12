// range: 0x208C20 0x208C50
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00265DF0(char *);                      /* extern */

void func_00208C20(char *arg0) {

    if (!(M2C_FIELD(arg0, s8 *, 0x67E0) == 0)) {
        return;
    }

    func_00265DF0(arg0 + 0x655C);
}

// range: 0x208C80 0x208CB0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00266120(char *);                      /* extern */

void func_00208C80(char *arg0) {

    if (!(M2C_FIELD(arg0, s8 *, 0x67E0) == 0)) {
        return;
    }

    func_00266120(arg0 + 0x655C);
}

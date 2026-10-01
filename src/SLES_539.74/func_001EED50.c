// range: 0x1EED50 0x1EED90
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001EED90();                            /* extern */
M2C_UNK func_001FAEA0(void *);                      /* extern */
extern M2C_UNK D_003DDF80 __attribute__((section(".data")));

void *func_001EED50(void *arg0) {
    func_001EED90();
    M2C_FIELD(arg0, M2C_UNK **, 0x68) = &D_003DDF80;
    func_001FAEA0(arg0);
    return arg0;
}

// range: 0x460990 0x4609D0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_004609D0();                            /* extern */
extern M2C_UNK D_3DE870 __attribute__((section(".data")));

char *func_00460990(char *arg0) {
    func_004609D0();
    M2C_FIELD(arg0, M2C_UNK **, 0x1B0) = &D_3DE870;
    return arg0;
}

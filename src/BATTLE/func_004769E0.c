// range: 0x4769E0 0x476A20
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00476A20();                            /* extern */
extern M2C_UNK D_3DE870 __attribute__((section(".data")));

char *func_004769E0(char *arg0) {
    func_00476A20();
    M2C_FIELD(arg0, M2C_UNK **, 0x1B0) = &D_3DE870;
    return arg0;
}

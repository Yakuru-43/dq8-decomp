// range: 0x253F30 0x253F70
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0016A5F0();                            /* extern */
extern M2C_UNK D_003DE870 __attribute__((section(".data")));

void *func_00253F30(void *arg0) {
    func_0016A5F0();
    M2C_FIELD(arg0, M2C_UNK **, 0x1B0) = &D_003DE870;
    return arg0;
}

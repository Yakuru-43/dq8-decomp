// range: 0x1EDD90 0x1EDDD0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001E4150();                            /* extern */
extern M2C_UNK D_003DDD70 __attribute__((section(".data")));

void *func_001EDD90(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x30) = &D_003DDD70;
    func_001E4150();
    return arg0;
}

// range: 0x153030 0x153050
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DD890 __attribute__((section(".data")));

void *func_00153030(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x40) = &D_003DD890;
    return arg0;
}

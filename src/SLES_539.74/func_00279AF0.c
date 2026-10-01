// range: 0x279AF0 0x279B00
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_00450D00 __attribute__((section(".data")));

M2C_UNK *func_00279AF0(void) {
    return &D_00450D00;
}

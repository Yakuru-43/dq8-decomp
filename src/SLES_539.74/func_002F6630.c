// range: 0x2F6630 0x2F6640
// auto: m2c, verified byte-exact
#include "common.h"

void func_002F6630(void *arg0, u8 arg1) {
    M2C_FIELD(arg0, u8 *, 0x11B4) = arg1;
    M2C_FIELD(arg0, u8 *, 0x11B5) = (u8) M2C_FIELD(arg0, u8 *, 0x11B4);
}

// range: 0x18F5A0 0x18F5C0
// auto: m2c, verified byte-exact
#include "common.h"

u32 func_0018F5A0(u32 arg0) {
    if (!(arg0 & 0xF)) {
        return arg0 >> 4;
    }
    return (arg0 >> 4) + 1;
}

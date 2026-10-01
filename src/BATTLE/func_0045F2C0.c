// range: 0x45F2C0 0x45F2E0
// auto: m2c draft, verified byte-exact
#include "common.h"

u32 func_0045F2C0(u32 arg0) {
    if (!(arg0 & 0xF)) {
        return arg0 >> 4;
    }
    return (arg0 >> 4) + 1;
}

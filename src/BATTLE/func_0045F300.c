// range: 0x45F300 0x45F320
// auto: m2c draft, verified byte-exact
#include "common.h"

u32 func_0045F300(u32 arg0) {
    if (!(arg0 & 0xF)) {
        return arg0 >> 4;
    }
    return (arg0 >> 4) + 1;
}

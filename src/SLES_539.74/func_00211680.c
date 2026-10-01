// range: 0x211680 0x2116A0
// auto: m2c, verified byte-exact
#include "common.h"

u32 func_00211680(u32 arg0) {
    if (!(arg0 & 0xF)) {
        return arg0 >> 4;
    }
    return (arg0 >> 4) + 1;
}

// range: 0x19DF10 0x19DFE0
#include "common.h"

u64 func_0019DF10(u64 arg0) {
    u64 hi = (arg0 >> 8) & 0xFF;
    u64 lo = arg0 & 0xFF;

    if (hi >= 0x81 && hi < 0xA0) {
        hi -= 0x81;
    } else if (hi >= 0xE0 && hi < 0xF0) {
        hi += -0xC1;
    }

    hi <<= 1;

    if (lo >= 0x40 && lo < 0x7F) {
        lo -= 0x40;
    } else if (lo >= 0x80 && lo < 0x9F) {
        lo += -0x41;
    } else if (lo >= 0x9F && lo < 0xFD) {
        lo -= 0x9F;
        hi += 1;
    }

    return ((hi + 1) << 8) + lo + 0x2021;
}

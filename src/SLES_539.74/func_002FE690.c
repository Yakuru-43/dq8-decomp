// range: 0x2FE690 0x2FE750
#include "common.h"

s32 func_002FE690(s32 arg0) {
    s32 v1;

    v1 = arg0 & 0xFFFF;
    if (0x3C < v1) {
        if (v1 < 0x56) {
            if (v1 == 0x40 || v1 == 0x44 || v1 == 0x4A || v1 == 0x50) {
                return 0;
            }
            return 1;
        }
    }
    if (0x1F < v1) {
        if (v1 < 0x39) {
            if (v1 == 0x23 || v1 == 0x27 || v1 == 0x2D || v1 == 0x33) {
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

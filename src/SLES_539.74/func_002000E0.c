// range: 0x2000E0 0x200200
#include "common.h"

s32 func_0022B3C0(s32);

void func_002000E0(s32 *arg0) {
    if (func_0022B3C0(0x1000)) {
        *arg0 |= 1;
    } else if (func_0022B3C0(0x4000)) {
        *arg0 |= 2;
    }
    if (func_0022B3C0(0x8000)) {
        *arg0 |= 4;
    } else if (func_0022B3C0(0x2000)) {
        *arg0 |= 8;
    } else if (func_0022B3C0(4)) {
        *arg0 |= 0x10;
    } else if (func_0022B3C0(8)) {
        *arg0 |= 0x20;
    } else if (func_0022B3C0(1)) {
        *arg0 |= 0x40;
    } else if (func_0022B3C0(2)) {
        *arg0 |= 0x80;
    }
}

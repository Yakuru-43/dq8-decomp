// range: 0x181610 0x181660
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003DFC1C;
extern s32 D_003DFC24;

void func_00181610(s32 arg0) {
    if (arg0 == 0) {
        D_003DFC1C = 0x20;
        D_003DFC24 = 0x40;
    }
    if (arg0 == 1) {
        D_003DFC1C = 0x40;
        D_003DFC24 = 0x20;
    }
}

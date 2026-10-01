// range: 0x176D80 0x176DA0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00176D80(s32 arg0, s32 arg1) {
    return (arg0 & 0xFFFF0000) | (arg1 & 0xFFFF);
}

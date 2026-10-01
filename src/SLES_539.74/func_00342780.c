// range: 0x342780 0x3427A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00342780(s32 arg0, s32 arg1) {
    return (arg1 & (1 << arg0)) != 0;
}

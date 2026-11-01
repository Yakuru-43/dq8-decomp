// range: 0x327A30 0x327A70
// auto: m2c draft, verified byte-exact
// flags: -flag divbyzerocheck
#include "common.h"

f32 func_00327A30(s32 arg0, s32 arg1) {
    return (1.0f + (f32) (arg1 / 5)) * (f32) arg0;
}

// range: 0x469550 0x469560
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2C];
    s32 unk2C;
} S_arg0;

s32 func_00469550(S_arg0 *arg0) {
    return arg0->unk2C;
}

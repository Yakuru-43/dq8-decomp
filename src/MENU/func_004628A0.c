// range: 0x4628A0 0x4628B0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2C];
    s32 unk2C;
    char pad30[0x4];
    s32 unk34;
} S_arg0;

s32 func_004628A0(S_arg0 *arg0) {
    return arg0->unk34 - arg0->unk2C;
}

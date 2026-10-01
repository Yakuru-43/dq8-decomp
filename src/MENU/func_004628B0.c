// range: 0x4628B0 0x4628D0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
} S_arg0;

s32 func_004628B0(S_arg0 *arg0) {
    return arg0->unk28 + (arg0->unk2C * 0x10);
}

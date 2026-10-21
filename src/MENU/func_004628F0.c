// range: 0x4628F0 0x462910
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
} S_arg0;

s32 func_004628F0(S_arg0 *arg0) {
    return arg0->unk28 + (arg0->unk2C * 0x10);
}

// range: 0x4628A0 0x4628B0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x508];
    s32 unk508;
} S_arg0;

s32 func_004628A0(S_arg0 *arg0, s32 arg1) {
    return arg0->unk508 & arg1;
}

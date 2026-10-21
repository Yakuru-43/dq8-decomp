// range: 0x468CE0 0x468CF0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x54C];
    s32 unk54C;
} S_arg0;

s32 func_00468CE0(S_arg0 *arg0) {
    return arg0->unk54C;
}

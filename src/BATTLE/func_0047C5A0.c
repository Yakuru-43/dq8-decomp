// range: 0x47C5A0 0x47C5B0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x34];
    s32 unk34;
} S_arg0;

s32 func_0047C5A0(S_arg0 *arg0) {
    return arg0->unk34;
}

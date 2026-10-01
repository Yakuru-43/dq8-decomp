// range: 0x47AF40 0x47AF60
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x64];
    s32 unk64;
    s32 unk68;
} S_arg0;

s32 func_0047AF40(S_arg0 *arg0, s32 *arg1) {
    if (arg1 != NULL) {
        *arg1 = arg0->unk64;
    }
    return arg0->unk68;
}

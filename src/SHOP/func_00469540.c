// range: 0x469540 0x469550
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x34];
    s32 unk34;
} S_arg0;

s32 func_00469540(S_arg0 *arg0) {
    return arg0->unk34;
}

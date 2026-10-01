// range: 0x4641D0 0x4641E0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xF20];
    s32 unkF20;
} S_arg0;

s32 func_004641D0(S_arg0 *arg0) {
    return arg0->unkF20;
}

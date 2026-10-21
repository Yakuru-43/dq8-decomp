// range: 0x46A0C0 0x46A0D0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x44B0];
    s32 unk44B0;
} S_arg0;

s32 func_0046A0C0(S_arg0 *arg0) {
    return arg0->unk44B0;
}

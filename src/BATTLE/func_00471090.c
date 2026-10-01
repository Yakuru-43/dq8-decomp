// range: 0x471090 0x4710A0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x74];
    s32 unk74;
} S_arg0;

s32 func_00471090(S_arg0 *arg0) {
    return arg0->unk74;
}

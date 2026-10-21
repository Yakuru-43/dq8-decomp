// range: 0x461670 0x461680
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2E];
    s8 unk2E;
} S_arg0;

s32 func_00461670(S_arg0 *arg0) {
    return arg0->unk2E != 0;
}

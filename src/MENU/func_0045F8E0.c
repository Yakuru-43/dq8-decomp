// range: 0x45F8E0 0x45F8F0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2E];
    s8 unk2E;
} S_arg0;

s32 func_0045F8E0(S_arg0 *arg0) {
    return arg0->unk2E != 0;
}

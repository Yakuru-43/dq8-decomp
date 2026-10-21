// range: 0x45F920 0x45F930
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2E];
    s8 unk2E;
} S_arg0;

s32 func_0045F920(S_arg0 *arg0) {
    return arg0->unk2E != 0;
}

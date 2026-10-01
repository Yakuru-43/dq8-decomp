// range: 0x45F0E0 0x45F0F0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x84];
    s32 unk84;
} S_arg0;

s32 func_0045F0E0(S_arg0 *arg0) {
    return arg0->unk84;
}

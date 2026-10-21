// range: 0x45F120 0x45F130
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x84];
    s32 unk84;
} S_arg0;

s32 func_0045F120(S_arg0 *arg0) {
    return arg0->unk84;
}

// range: 0x45F350 0x45F360
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x84];
    s32 unk84;
} S_arg0;

s32 func_0045F350(S_arg0 *arg0) {
    return arg0->unk84;
}

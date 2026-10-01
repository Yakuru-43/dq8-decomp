// range: 0x472020 0x472030
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x6B10];
    f32 unk6B10;
} S_arg0;

f32 func_00472020(S_arg0 *arg0) {
    return arg0->unk6B10;
}

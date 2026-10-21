// range: 0x472060 0x472070
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x6B10];
    f32 unk6B10;
} S_arg0;

f32 func_00472060(S_arg0 *arg0) {
    return arg0->unk6B10;
}

// range: 0x46CA90 0x46CAA0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x18];
    s32 unk18;
} S_arg0;

s32 func_0046CA90(S_arg0 *arg0) {
    return arg0->unk18;
}

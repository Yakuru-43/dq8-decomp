// range: 0x45ED80 0x45ED90
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x14];
    s32 unk14;
} S_arg0;

s32 func_0045ED80(S_arg0 *arg0) {
    return arg0->unk14;
}

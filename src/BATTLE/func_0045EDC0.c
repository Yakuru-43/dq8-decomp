// range: 0x45EDC0 0x45EDD0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x14];
    s32 unk14;
} S_arg0;

s32 func_0045EDC0(S_arg0 *arg0) {
    return arg0->unk14;
}

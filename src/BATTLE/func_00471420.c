// range: 0x471420 0x471430
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4FC];
    s32 unk4FC;
} S_arg0;

s32 func_00471420(S_arg0 *arg0) {
    return arg0->unk4FC;
}

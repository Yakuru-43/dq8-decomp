// range: 0x4713E0 0x4713F0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4FC];
    s32 unk4FC;
} S_arg0;

s32 func_004713E0(S_arg0 *arg0) {
    return arg0->unk4FC;
}

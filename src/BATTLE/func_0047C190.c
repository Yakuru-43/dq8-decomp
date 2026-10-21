// range: 0x47C190 0x47C1A0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x3B90];
    s32 unk3B90;
} S_arg0;

s32 func_0047C190(S_arg0 *arg0) {
    return arg0->unk3B90;
}

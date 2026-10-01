// range: 0x45F0D0 0x45F0E0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x58];
    s32 unk58;
} S_arg0;

s32 func_0045F0D0(S_arg0 *arg0) {
    return arg0->unk58;
}

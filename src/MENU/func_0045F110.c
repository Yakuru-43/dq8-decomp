// range: 0x45F110 0x45F120
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x58];
    s32 unk58;
} S_arg0;

s32 func_0045F110(S_arg0 *arg0) {
    return arg0->unk58;
}

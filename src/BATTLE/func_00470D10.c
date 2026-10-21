// range: 0x470D10 0x470D20
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x18];
    s32 unk18;
} S_arg0;

s32 func_00470D10(S_arg0 *arg0) {
    return arg0->unk18 & 0x10;
}

// range: 0x470CD0 0x470CE0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x18];
    s32 unk18;
} S_arg0;

s32 func_00470CD0(S_arg0 *arg0) {
    return arg0->unk18 & 0x10;
}

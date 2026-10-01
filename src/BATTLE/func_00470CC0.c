// range: 0x470CC0 0x470CD0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x388];
    s8 unk388;
} S_arg0;

s8 func_00470CC0(S_arg0 *arg0) {
    return arg0->unk388;
}

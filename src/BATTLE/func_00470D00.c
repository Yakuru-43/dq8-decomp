// range: 0x470D00 0x470D10
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x388];
    s8 unk388;
} S_arg0;

s8 func_00470D00(S_arg0 *arg0) {
    return arg0->unk388;
}

// range: 0x4710E0 0x4710F0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xA6];
    s16 unkA6;
} S_arg0;

s16 func_004710E0(S_arg0 *arg0) {
    return arg0->unkA6;
}

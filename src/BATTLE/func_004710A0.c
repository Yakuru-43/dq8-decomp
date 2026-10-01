// range: 0x4710A0 0x4710B0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xA6];
    s16 unkA6;
} S_arg0;

s16 func_004710A0(S_arg0 *arg0) {
    return arg0->unkA6;
}

// range: 0x4713D0 0x4713E0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x500];
    s32 unk500;
} S_arg0;

s32 func_004713D0(S_arg0 *arg0) {
    return arg0->unk500;
}

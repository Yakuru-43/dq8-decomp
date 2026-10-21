// range: 0x472370 0x472380
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x44C];
    s32 unk44C;
} S_arg0;

void func_00472370(S_arg0 *arg0, s32 arg1) {
    arg0->unk44C = arg1;
}

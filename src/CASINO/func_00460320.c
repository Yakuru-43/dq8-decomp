// range: 0x460320 0x460330
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
} S_arg0;

void func_00460320(S_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
}

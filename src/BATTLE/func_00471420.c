// range: 0x471420 0x471430
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x534];
    s32 unk534;
} S_arg0;

void func_00471420(S_arg0 *arg0, s32 arg1) {
    arg0->unk534 = arg1;
}

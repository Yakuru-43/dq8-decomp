// range: 0x470CF0 0x470D00
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4];
    s32 unk4;
} S_arg0;

void func_00470CF0(S_arg0 *arg0, s32 arg1) {
    arg0->unk4 = arg1;
}

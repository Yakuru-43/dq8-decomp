// range: 0x4768B0 0x4768C0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x500];
    s32 unk500;
} S_arg0;

void func_004768B0(S_arg0 *arg0, s32 arg1) {
    arg0->unk500 = arg1;
}

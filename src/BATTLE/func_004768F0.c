// range: 0x4768F0 0x476900
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x500];
    s32 unk500;
} S_arg0;

void func_004768F0(S_arg0 *arg0, s32 arg1) {
    arg0->unk500 = arg1;
}

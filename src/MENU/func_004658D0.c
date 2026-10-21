// range: 0x4658D0 0x4658E0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x14];
    s32 unk14;
} S_arg0;

void func_004658D0(S_arg0 *arg0, s32 arg1) {
    arg0->unk14 = (s32) (arg0->unk14 | arg1);
}

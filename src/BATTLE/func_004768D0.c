// range: 0x4768D0 0x4768F0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1C8];
    s32 unk1C8;
} S_arg0;

void func_004768D0(S_arg0 *arg0, M2C_UNK arg1) {
    arg0->unk1C8 = (s32) (arg0->unk1C8 & ~arg1);
}

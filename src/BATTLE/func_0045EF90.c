// range: 0x45EF90 0x45EFA0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1C8];
    s32 unk1C8;
} S_arg0;

void func_0045EF90(S_arg0 *arg0, s32 arg1) {
    arg0->unk1C8 = (s32) (arg0->unk1C8 | arg1);
}

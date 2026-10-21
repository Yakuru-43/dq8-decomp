// range: 0x45EFD0 0x45EFE0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1C8];
    s32 unk1C8;
} S_arg0;

void func_0045EFD0(S_arg0 *arg0, s32 arg1) {
    arg0->unk1C8 = (s32) (arg0->unk1C8 | arg1);
}

// range: 0x461BF0 0x461C00
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x4];
    s32 unk14;
    s32 unk18;
} S_arg0;

void func_00461BF0(S_arg0 *arg0) {
    arg0->unkC = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
}

// range: 0x3757C0 0x3757E0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
} S_arg0;

void func_003757C0(S_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    arg0->unk4 = fparg0;
    arg0->unk8 = fparg1;
    arg0->unkC = fparg2;
    arg0->unk10 = fparg3;
}

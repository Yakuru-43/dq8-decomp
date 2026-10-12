// range: 0x460730 0x460750
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x40];
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
} S_arg0;

void func_00460730(S_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    arg0->unk40 = fparg0;
    arg0->unk44 = fparg1;
    arg0->unk48 = fparg2;
    arg0->unk4C = fparg3;
}

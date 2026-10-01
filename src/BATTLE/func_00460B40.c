// range: 0x460B40 0x460B60
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} S_arg0;

void func_00460B40(S_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    arg0->unk0 = fparg0;
    arg0->unk4 = fparg1;
    arg0->unk8 = fparg2;
    arg0->unkC = fparg3;
}

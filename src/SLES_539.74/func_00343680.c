// range: 0x343680 0x343690
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1D8];
    f32 unk1D8;
} S_arg0;

void func_00343680(S_arg0 *arg0, f32 fparg0) {
    arg0->unk1D8 = fparg0;
}

// range: 0x167550 0x167590
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x100];
    f32 unk100;
    f32 unk104;
} S_arg0;

void func_00167550(S_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk100 = fparg0;
    if (!(fparg1 < 0.0f)) {
        arg0->unk104 = fparg1;
    } else {
        arg0->unk104 = (f32) arg0->unk100;
    }
}

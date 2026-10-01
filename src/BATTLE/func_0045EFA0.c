// range: 0x45EFA0 0x45EFB0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1E8];
    f32 unk1E8;
} S_arg0;

void func_0045EFA0(S_arg0 *arg0, f32 fparg0) {
    arg0->unk1E8 = fparg0;
}

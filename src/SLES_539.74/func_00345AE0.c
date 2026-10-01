// range: 0x345AE0 0x345AF0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1D4];
    f32 unk1D4;
} S_arg0;

void func_00345AE0(S_arg0 *arg0, f32 fparg0) {
    arg0->unk1D4 = fparg0;
}

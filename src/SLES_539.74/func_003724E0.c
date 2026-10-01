// range: 0x3724E0 0x372520
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x14];
    f32 unk14;
    char pad18[0x4];
    f32 unk1C;
    f32 unk20;
} S_arg0;

void func_003724E0(S_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk1C = fparg0;
    arg0->unk20 = (f32) (((fparg0 - arg0->unk14) / fparg1) / 50.0f);
}

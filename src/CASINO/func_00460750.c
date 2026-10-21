// range: 0x460750 0x460760
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x38];
    f32 unk38;
    f32 unk3C;
} S_arg0;

void func_00460750(S_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk38 = fparg0;
    arg0->unk3C = fparg1;
}

// range: 0x4768F0 0x476900
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1E4];
    f32 unk1E4;
} S_arg0;

void func_004768F0(S_arg0 *arg0, f32 fparg0) {
    arg0->unk1E4 = fparg0;
}

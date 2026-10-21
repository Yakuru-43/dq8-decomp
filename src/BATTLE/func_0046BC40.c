// range: 0x46BC40 0x46BC50
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x228];
    f32 unk228;
} S_arg0;

void func_0046BC40(S_arg0 *arg0, f32 fparg0) {
    arg0->unk228 = fparg0;
}

// range: 0x1ECAD0 0x1ECAF0
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E078C;
extern s32 D_003E0790;
extern s32 D_003E0794;

s32 func_001ECAD0(void) {
    D_003E0794 = 0;
    D_003E0790 = 0;
    D_003E078C += 1;
    return 1;
}

// range: 0x304AD0 0x304B30
// auto: hand, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x20];
    f32 unk20;
} S_arg0;

f32 func_00304AD0(S_arg0 *arg0, s32 arg1) {
    if (arg1 == 1) {
        return arg0->unk20 / (f32) 20000;
    }
    if (arg1 == 2) {
        return 10.0f * (arg0->unk20 / (f32) 20000);
    }
    return arg0->unk20;
}

// range: 0x304C00 0x304C60
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4050];
    f32 unk4050;
} S_arg0;

void func_00304C00(S_arg0 *arg0, f32 fparg0) {
    f32 temp_f1;
    f32 temp_f1_2;

    temp_f1 = arg0->unk4050 + fparg0;
    arg0->unk4050 = temp_f1;
    if (temp_f1 < 0.0f) {
        arg0->unk4050 = 0.0f;
    }
    temp_f1_2 = (f32) 0x186A0;
    if (temp_f1_2 < arg0->unk4050) {
        arg0->unk4050 = temp_f1_2;
    }
}

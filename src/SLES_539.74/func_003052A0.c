// range: 0x3052A0 0x305300
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x20];
    f32 unk20;
} S_arg0;

void func_003052A0(S_arg0 *arg0, f32 fparg0) {
    f32 temp_f1;
    f32 temp_f1_2;

    temp_f1 = arg0->unk20 + fparg0;
    arg0->unk20 = temp_f1;
    if (temp_f1 < 0.0f) {
        arg0->unk20 = 0.0f;
    }
    temp_f1_2 = (f32) 0x0BEB73E0;
    if (temp_f1_2 < arg0->unk20) {
        arg0->unk20 = temp_f1_2;
    }
}

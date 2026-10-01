// range: 0x271750 0x2717A0
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x7C];
    f32 unk80;
    f32 unk84;
    f32 unk88;
} S_arg1;

void func_00271750(s32 arg0, S_arg1 *arg1) {
    f32 temp_f0;

    temp_f0 = func_002675D0(arg1->unk0);
    arg1->unk80 = (f32) (arg1->unk80 * temp_f0);
    arg1->unk84 = (f32) (arg1->unk84 * temp_f0);
    arg1->unk88 = (f32) (arg1->unk88 * temp_f0);
}

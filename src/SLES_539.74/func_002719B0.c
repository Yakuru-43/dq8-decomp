// range: 0x2719B0 0x271A00
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x5C];
    f32 unk60;
    f32 unk64;
    f32 unk68;
} S_arg1;

void func_002719B0(s32 arg0, S_arg1 *arg1) {
    f32 temp_f0;

    temp_f0 = func_002675D0(arg1->unk0);
    arg1->unk60 = (f32) (arg1->unk60 + temp_f0);
    arg1->unk64 = (f32) (arg1->unk64 + temp_f0);
    arg1->unk68 = (f32) (arg1->unk68 + temp_f0);
}

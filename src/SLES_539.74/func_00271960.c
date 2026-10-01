// range: 0x271960 0x2719B0
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x6C];
    f32 unk70;
    f32 unk74;
    f32 unk78;
} S_arg1;

void func_00271960(s32 arg0, S_arg1 *arg1) {
    f32 temp_f0;

    temp_f0 = func_002675D0(arg1->unk0);
    arg1->unk70 = (f32) (arg1->unk70 + temp_f0);
    arg1->unk74 = (f32) (arg1->unk74 + temp_f0);
    arg1->unk78 = (f32) (arg1->unk78 + temp_f0);
}

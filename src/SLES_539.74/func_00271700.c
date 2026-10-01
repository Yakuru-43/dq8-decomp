// range: 0x271700 0x271750
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x8C];
    f32 unk90;
    f32 unk94;
    f32 unk98;
} S_arg1;

void func_00271700(s32 arg0, S_arg1 *arg1) {
    f32 temp_f0;

    temp_f0 = func_002675D0(arg1->unk0);
    arg1->unk90 = (f32) (arg1->unk90 * temp_f0);
    arg1->unk94 = (f32) (arg1->unk94 * temp_f0);
    arg1->unk98 = (f32) (arg1->unk98 * temp_f0);
}

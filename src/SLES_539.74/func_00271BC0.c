// range: 0x271BC0 0x271C00
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x5C];
    f32 unk60;
} S_arg1;

void func_00271BC0(s32 arg0, S_arg1 *arg1) {
    arg1->unk60 = (f32) (arg1->unk60 + func_002675D0(arg1->unk0));
}

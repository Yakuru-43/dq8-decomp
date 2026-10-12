// range: 0x271A40 0x271A80
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x9C];
    f32 unkA0;
} S_arg1;

void func_00271A40(s32 arg0, S_arg1 *arg1) {
    arg1->unkA0 = (f32) (arg1->unkA0 + func_002675D0(arg1->unk0));
}

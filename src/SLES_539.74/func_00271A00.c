// range: 0x271A00 0x271A40
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0xA0];
    f32 unkA4;
} S_arg1;

void func_00271A00(s32 arg0, S_arg1 *arg1) {
    arg1->unkA4 = (f32) (arg1->unkA4 + func_002675D0(arg1->unk0));
}

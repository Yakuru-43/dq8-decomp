// range: 0x271B00 0x271B40
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x6C];
    f32 unk70;
} S_arg1;

void func_00271B00(s32 arg0, S_arg1 *arg1) {
    arg1->unk70 = (f32) (arg1->unk70 + func_002675D0(arg1->unk0));
}

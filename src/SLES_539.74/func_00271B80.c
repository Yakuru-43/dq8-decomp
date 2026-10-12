// range: 0x271B80 0x271BC0
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x60];
    f32 unk64;
} S_arg1;

void func_00271B80(s32 arg0, S_arg1 *arg1) {
    arg1->unk64 = (f32) (arg1->unk64 + func_002675D0(arg1->unk0));
}

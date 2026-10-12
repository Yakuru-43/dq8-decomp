// range: 0x271820 0x271860
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x90];
    f32 unk94;
} S_arg1;

void func_00271820(s32 arg0, S_arg1 *arg1) {
    arg1->unk94 = (f32) (arg1->unk94 * func_002675D0(arg1->unk0));
}

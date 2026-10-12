// range: 0x271920 0x271960
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x7C];
    f32 unk80;
} S_arg1;

void func_00271920(s32 arg0, S_arg1 *arg1) {
    arg1->unk80 = (f32) (arg1->unk80 * func_002675D0(arg1->unk0));
}

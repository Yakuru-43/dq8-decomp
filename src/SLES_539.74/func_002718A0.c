// range: 0x2718A0 0x2718E0
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x84];
    f32 unk88;
} S_arg1;

void func_002718A0(s32 arg0, S_arg1 *arg1) {
    arg1->unk88 = (f32) (arg1->unk88 * func_002675D0(arg1->unk0));
}

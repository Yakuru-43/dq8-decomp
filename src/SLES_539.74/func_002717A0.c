// range: 0x2717A0 0x2717E0
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x98];
    f32 unk9C;
} S_arg1;

void func_002717A0(s32 arg0, S_arg1 *arg1) {
    arg1->unk9C = (f32) (arg1->unk9C * func_002675D0(arg1->unk0));
}

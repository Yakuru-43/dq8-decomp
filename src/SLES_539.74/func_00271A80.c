// range: 0x271A80 0x271AC0
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_002675D0(f32);                             /* extern */

typedef struct {
    f32 unk0;
    char pad4[0x74];
    f32 unk78;
} S_arg1;

void func_00271A80(s32 arg0, S_arg1 *arg1) {
    arg1->unk78 = (f32) (arg1->unk78 + func_002675D0(arg1->unk0));
}

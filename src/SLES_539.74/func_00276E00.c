// range: 0x276E00 0x276E50
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_0013D3E0();                             /* extern */

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
} S_arg1;

void func_00276E00(s32 arg0, S_arg1 *arg1) {
    arg1->unk0 = func_0013D3E0();
    arg1->unk4 = func_0013D3E0(arg0 + 0x10);
    arg1->unk8 = func_0013D3E0(arg0 + 0x20);
    arg1->unkC = 0;
}

// range: 0x19A0D0 0x19A110
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    f32 unk0;
    char pad4[0x4];
    f32 unk8;
} S_arg0;

typedef struct {
    f32 unk0;
    char pad4[0x4];
    f32 unk8;
} S_arg1;

void func_0019A0D0(S_arg0 *arg0, S_arg1 *arg1) {
    arg0->unk0 = (f32) (arg1->unk0 - (f32) 0x2710);
    arg0->unk8 = (f32) ((f32) 0x1770 + arg1->unk8);
}

// range: 0x19AE30 0x19AEC0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    s32 unk1C;
    s32 unk20;
    f32 unk24;
} S_arg0;

void func_0019AE30(S_arg0 *arg0, s32 arg1, s32 arg2, f32 fparg0) {
    arg0->unk1C = arg1;
    if ((arg0->unk10 == 0) || (arg2 < 0)) {
        arg0->unkC = 0;
    }
    arg0->unk10 = -1;
    arg0->unk14 = 0;
    if (arg2 >= 0) {
        arg0->unk18 = (f32) (128.0f / (f32) arg2);
    } else {
        arg0->unk18 = 0.0f;
    }
    arg0->unk0 = 0x43000000;
    arg0->unk4 = 0x43000000;
    arg0->unk8 = 0x43000000;
    arg0->unk20 = 0;
    arg0->unkC = 0;
    arg0->unk20 = 1;
    arg0->unk24 = fparg0;
}

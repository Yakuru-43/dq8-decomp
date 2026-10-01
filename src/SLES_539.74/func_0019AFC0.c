// range: 0x19AFC0 0x19B030
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    char pad1C[0x4];
    s32 unk20;
} S_arg0;

void func_0019AFC0(S_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    if ((arg0->unk10 == 0) || (arg1 < 0)) {
        arg0->unkC = 0;
    }
    arg0->unk10 = -1;
    arg0->unk14 = 0;
    if (arg1 >= 0) {
        arg0->unk18 = (f32) (128.0f / (f32) arg1);
    } else {
        arg0->unk18 = 0.0f;
    }
    arg0->unk0 = fparg0;
    arg0->unk4 = fparg1;
    arg0->unk8 = fparg2;
    arg0->unk20 = 0;
}

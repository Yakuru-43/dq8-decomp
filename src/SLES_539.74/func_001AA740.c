// range: 0x1AA740 0x1AA760
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xB4];
    f32 unkB4;
    char padB8[0xC];
    f32 unkC4;
    char padC8[0xC];
    f32 unkD4;
} S_arg1;

typedef struct {
    char pad0[0x30];
    f32 unk30;
} S_arg0;

s32 func_001AA740(S_arg0 *arg0, S_arg1 *arg1) {
    arg1->unkB4 = (f32) (arg0->unk30 + arg1->unkC4);
    arg1->unkD4 = (f32) arg0->unk30;
    return 0;
}

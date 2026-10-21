// range: 0x46E640 0x46E670
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s8 unkC;
    s8 unkD;
    char padE[0x6];
    s32 unk14;
    s32 unk18;
} S_arg1;

void func_0046E640(s32 arg0, S_arg1 *arg1) {
    arg1->unk0 = -1;
    arg1->unk4 = 0;
    arg1->unk8 = -1;
    arg1->unk14 = -1;
    arg1->unkC = 0;
    arg1->unkD = 0;
    arg1->unk18 = 0;
    arg1->unkA = -1;
}

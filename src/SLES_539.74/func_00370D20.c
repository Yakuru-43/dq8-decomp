// range: 0x370D20 0x370D40
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x14];
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
} S_arg1;

void func_00370D20(s32 arg0, S_arg1 *arg1) {
    arg1->unk16 = 0;
    arg1->unk14 = 0;
    arg1->unk1A = 0;
    arg1->unk18 = 0;
}

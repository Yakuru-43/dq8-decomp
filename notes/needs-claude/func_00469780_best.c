// range: 0x469780 0x4698D0
// best attempt: try_match --bin CASINO -- -O3 -> CLASS reorder+register score=10
// (332 vs 332 bytes; the 10 "differing" words are the f1/f2 swap of the two
//  float constants plus unresolved %gp_rel/jal relocations)
#include "common.h"

extern f32 func_13BCA0(f32);

typedef struct {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[8];
    f32 unk10;
    u8 pad14[0x34 - 0x14];
    f32 unk34;
    u8 pad38[0x40 - 0x38];
} S_slot;

extern S_slot *D_003E17B0 __attribute__((section(".sdata")));
extern f32 D_003DF764 __attribute__((section(".sdata")));
extern f32 D_003DF6D4 __attribute__((section(".sdata")));

s32 func_00469780(void) {
    f32 add34;
    f32 add10;
    s32 i;
    s32 j;

    i = 0;
    j = 5;
    do {
        add10 = D_003DF6D4;
        add34 = D_003DF764;
        D_003E17B0[i].unk34 += add34;
        D_003E17B0[j].unk34 += add34;
        D_003E17B0[i].unk4 -= D_003E17B0[i].unk34;
        D_003E17B0[j].unk4 -= D_003E17B0[i].unk34;
        D_003E17B0[i].unk10 += add10;
        D_003E17B0[j].unk10 += add10;
        D_003E17B0[i].unk10 = func_13BCA0(D_003E17B0[i].unk10);
        D_003E17B0[j].unk10 = func_13BCA0(D_003E17B0[j].unk10);
        i++;
        j++;
    } while (i < 5);
    if (D_003E17B0[4].unk4 < 0.0f && D_003E17B0[9].unk4 < 0.0f) {
        return 1;
    }
    return 0;
}

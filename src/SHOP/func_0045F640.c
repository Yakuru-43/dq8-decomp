// range: 0x45F640 0x45F690
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct {
    char pad0[0x4];
    s16 unk4;
} S_415EA4;

s32 func_24D380(s32, s32, s32);
extern S_415EA4 *D_00415EA4 __attribute__((section(".data")));

s32 func_0045F640(s32 arg0) {
    s32 v = func_24D380(arg0, 0, 0);
    s32 rate = D_00415EA4->unk4;

    return v * rate / 100;
}

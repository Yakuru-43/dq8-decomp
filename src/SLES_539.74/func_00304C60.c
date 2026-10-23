// range: 0x304C60 0x304CC0
// auto: hand, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4040];
    s32 unk4040[4];
} S_arg0;

void func_00304C60(S_arg0 *arg0, s32 arg1) {
    if (arg1 < 0) {
        return;
    }
    if (arg1 >= 4) {
        return;
    }
    if (arg0->unk4040[arg1] < 0x7FFFFFFE) {
        arg0->unk4040[arg1] = arg0->unk4040[arg1] + 1;
    }
}

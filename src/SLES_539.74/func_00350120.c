// range: 0x350120 0x350170
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4];
    s32 unk4;
} S_arg0;

void func_00350120(S_arg0 *arg0, s32 arg1) {
    arg0->unk4 = (s32) (arg0->unk4 + arg1);
    if (arg0->unk4 >= 8) {
        arg0->unk4 = 7;
    }
    if (arg0->unk4 < -7) {
        arg0->unk4 = -7;
    }
}

// range: 0x191130 0x191150
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x539C];
    s32 unk539C;
    char pad53A0[0x4];
    s32 unk53A4;
} S_arg0;

void func_00191130(S_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg0->unk539C;
    if (temp_v1 != arg1) {
        arg0->unk53A4 = temp_v1;
    }
    arg0->unk539C = arg1;
}

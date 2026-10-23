// range: 0x304BC0 0x304C00
// auto: hand, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4054];
    s32 unk4054;
} S_arg0;

void func_00304BC0(S_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg0->unk4054 + arg1;
    if (temp_v1 < 0) {
        temp_v1 = 0;
    }
    if (temp_v1 > 0x7FFFFFFE) {
        temp_v1 = 0x7FFFFFFE;
    }
    arg0->unk4054 = temp_v1;
}

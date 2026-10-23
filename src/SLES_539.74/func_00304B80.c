// range: 0x304B80 0x304BC0
// auto: hand, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4058];
    s32 unk4058;
} S_arg0;

void func_00304B80(S_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg0->unk4058 + arg1;
    if (temp_v1 < 0) {
        temp_v1 = 0;
    }
    if (temp_v1 > 0x7FFFFFFE) {
        temp_v1 = 0x7FFFFFFE;
    }
    arg0->unk4058 = temp_v1;
}

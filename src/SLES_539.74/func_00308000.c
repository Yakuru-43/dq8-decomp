// range: 0x308000 0x308030
// auto: hand, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x16C];
    s16 unk16C;
} S_arg0;

void func_00308000(S_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 + arg0->unk16C;
    if (temp_v1 < 0) {
        temp_v1 = 0;
    }
    if (temp_v1 > 0x7FFE) {
        temp_v1 = 0x7FFE;
    }
    arg0->unk16C = temp_v1;
}

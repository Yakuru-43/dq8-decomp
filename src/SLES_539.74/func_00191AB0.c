// range: 0x191AB0 0x191AD0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x5398];
    s32 unk5398;
    char pad539C[0x4];
    s32 unk53A0;
} S_arg0;

void func_00191AB0(S_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg0->unk5398;
    if (temp_v1 != arg1) {
        arg0->unk53A0 = temp_v1;
    }
    arg0->unk5398 = arg1;
}

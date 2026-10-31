// range: 0x35C910 0x35C950
#include "common.h"

M2C_UNK func_0035CE50();                            /* extern */

typedef struct {
    char pad0[0x8A];
    s16 unk8A;
    char pad8C[0x16];
    s16 unkA2;
} S_arg0;

s32 func_0035C910(S_arg0 *arg0) {
    s32 temp_s0;

    temp_s0 = arg0->unk8A;
    arg0->unkA2 = 0;
    func_0035CE50();
    return arg0->unk8A - temp_s0;
}

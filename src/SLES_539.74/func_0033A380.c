// range: 0x33A380 0x33A400
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0033A710(s32);                         /* extern */

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} S_arg0;

void func_0033A380(S_arg0 *arg0) {
    s32 var_s0;

    arg0->unk0 = 0;
    arg0->unk4 = 0;
    if (arg0->unk8 != 0) {
        var_s0 = 0;
        do {
            func_0033A710(arg0->unk8 + (var_s0 * 0x220));
            var_s0 += 1;
        } while (var_s0 < 0x20);
    }
    arg0->unk10 = 0;
    arg0->unkC = 0;
}

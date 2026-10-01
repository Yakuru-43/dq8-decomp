// range: 0x30B070 0x30B100
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0030AAE0(s32);                             /* extern */
s32 func_0030B100(s32);                             /* extern */
M2C_UNK func_00356910(s32, M2C_UNK);                /* extern */

typedef struct {
    char pad0[0x128];
    s32 unk128;
    char pad12C[0x8];
    s32 unk134;
} S_arg1;

void func_0030B070(s32 arg0, S_arg1 *arg1) {
    M2C_UNK var_s1;
    s32 temp_a0;
    s32 temp_s0;

    var_s1 = 0;
    temp_a0 = arg1->unk128;
    if ((temp_a0 != 0) && (func_0030B100(temp_a0) != 0)) {
        var_s1 = 1;
        temp_s0 = func_0030B100(arg1->unk128);
        if (temp_s0 & func_0030AAE0(arg1->unk134)) {
            var_s1 = 0;
        }
    }
    func_00356910(arg0, var_s1);
}

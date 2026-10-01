// range: 0x30B110 0x30B180
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_0030B180(s32);                             /* extern */
s32 func_0030B190(s32);                             /* extern */
M2C_UNK func_003568F0(s32, f32);                    /* extern */
M2C_UNK func_00356910(s32, M2C_UNK);                /* extern */

typedef struct {
    char pad0[0x130];
    s32 unk130;
} S_arg1;

void func_0030B110(s32 arg0, S_arg1 *arg1) {
    s32 temp_a0;

    temp_a0 = arg1->unk130;
    if ((temp_a0 != 0) && (func_0030B190(temp_a0) == 0)) {
        func_003568F0(arg0, func_0030B180(arg1->unk130));
        return;
    }
    func_00356910(arg0, 0);
}

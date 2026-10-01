// range: 0x30B960 0x30B9E0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00356910(s32, M2C_UNK);                /* extern */
s32 func_0035D590(s32);                             /* extern */
s32 func_0035DC80(s32);                             /* extern */

typedef struct {
    char pad0[0x158];
    s32 unk158;
} S_arg1;

void func_0030B960(s32 arg0, S_arg1 *arg1) {
    if ((func_0035D590(arg1->unk158) == 3) && (func_0035DC80(arg1->unk158) == 4)) {
        func_00356910(arg0, 1);
        return;
    }
    func_00356910(arg0, 0);
}

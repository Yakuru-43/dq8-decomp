// range: 0x14A450 0x14A490
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0014A2F0();         /* extern */

typedef struct {
    char pad0[0x4];
    s32 unk4;
} S_arg0;

void func_0014A450(S_arg0 *arg0, s32 arg1) {
    if (arg0->unk4 == 0) {
        arg0->unk4 = arg1;
        if (arg1 != 0) {
            func_0014A2F0(arg1, arg0, arg0);
        }
    }
}

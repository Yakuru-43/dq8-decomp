// range: 0x461790 0x4617F0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00461830();             /* extern */
M2C_UNK func_22AB50();                       /* extern */
M2C_UNK func_370C00();       /* extern */
extern M2C_UNK D_00473740 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_00461790(S_arg0 *arg0, M2C_UNK arg1) {
    func_22AB50(0);
    func_00461830(arg0, arg1);
    func_370C00(arg0->unk20, &D_00473740, 0);
    return 1;
}

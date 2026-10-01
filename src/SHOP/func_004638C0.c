// range: 0x4638C0 0x463900
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00463D40();                            /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
extern M2C_UNK D_00473578 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_004638C0(S_arg0 *arg0) {
    func_00463D40();
    func_370C00(arg0->unk20, &D_00473578, 0);
    return 1;
}

// range: 0x46C550 0x46C590
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_22AB50(M2C_UNK);                       /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
extern M2C_UNK D_00473B10 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_0046C550(S_arg0 *arg0) {
    func_22AB50(0);
    func_370C00(arg0->unk20, &D_00473B10, 1);
    return 1;
}

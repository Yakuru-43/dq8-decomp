// range: 0x46D1C0 0x46D1F0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
extern M2C_UNK D_00473AC8 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_0046D1C0(S_arg0 *arg0) {
    func_370C00(arg0->unk20, &D_00473AC8, 0);
    return 1;
}

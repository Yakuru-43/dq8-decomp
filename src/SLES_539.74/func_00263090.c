// range: 0x263090 0x2630C0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001EA0A0(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_003C9718 __attribute__((section(".data")));

s32 func_00263090(void *arg0) {
    func_001EA0A0(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x40), &D_003C9718, 0);
    return 0;
}

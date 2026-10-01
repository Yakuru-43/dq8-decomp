// range: 0x23DC70 0x23DCA0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(s32, s32);                    /* extern */
extern s32 D_003E0B24;

s32 func_0023DC70(void *arg0) {
    func_001340C0(D_003E0B24 + 0x30, M2C_FIELD(arg0, s32 *, 4));
    return 1;
}

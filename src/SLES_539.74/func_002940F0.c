// range: 0x2940F0 0x294130
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002914D0();                            /* extern */

s32 func_002940F0(void *arg0) {
    if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x58C), s32 *, 0x358) & 0x200)) {
        return 0;
    }
    func_002914D0();
    return 1;
}

// range: 0x294190 0x294210
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002914D0(void *);                      /* extern */
s32 func_002915F0(void *, M2C_UNK);                 /* extern */
M2C_UNK func_00292460(void *, M2C_UNK);             /* extern */
M2C_UNK func_00292960();                            /* extern */

s32 func_00294190(void *arg0) {
    if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x58C), s32 *, 0x358) & 0x80)) {
        return 0;
    }
    func_00292960();
    func_00292460(arg0, 0x04000000);
    if (func_002915F0(arg0, 0) > 0) {
        func_002914D0(arg0);
        return 1;
    }
    return 0;
}

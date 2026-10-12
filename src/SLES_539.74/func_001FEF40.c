// range: 0x1FEF40 0x1FEF80
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001FEBC0();                            /* extern */

void func_001FEF40(char *arg0) {

    if (!(M2C_FIELD(arg0, s32 *, 0x1754) != 0)) {
        return;
    }

    if (M2C_FIELD(arg0, s32 *, 0x11A0) == 0) {
        return;
    }
    func_001FEBC0();
}

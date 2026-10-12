// range: 0x350E20 0x350E60
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_003515A0();                                /* extern */
extern char *D_003E1374;

void func_00350E20(s32 arg0) {

    if (!(func_003515A0() != 0)) {
        return;
    }

    M2C_FIELD(D_003E1374, s32 *, 0xC) = arg0;
}

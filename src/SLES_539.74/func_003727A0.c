// range: 0x3727A0 0x3727D0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0025ADC0(s16);                         /* extern */

void func_003727A0(char *arg0) {

    if (!(M2C_FIELD(arg0, u8 *, 0) != 0)) {
        return;
    }

    func_0025ADC0(M2C_FIELD(arg0, s16 *, 2));
}

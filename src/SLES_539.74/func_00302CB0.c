// range: 0x302CB0 0x302D00
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_0013D340(s128 *, s128 *);                  /* extern */

f32 func_00302CB0(char *arg0, char *arg1) {
    s128 sp20;
    s128 sp10;
    f32 var_f0;

    var_f0 = -1.0f;
    sp20 = 0;
    sp10 = 0;
    if ((arg0 != NULL) && (arg1 != NULL)) {
        sp20 = M2C_FIELD(arg0, s128 *, 0x180);
        sp10 = M2C_FIELD(arg1, s128 *, 0x180);
        var_f0 = func_0013D340(&sp20, &sp10);
    }
    return var_f0;
}

// range: 0x18CAD0 0x18CB10
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0018CAD0(char *arg0) {
    s8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 *, 0x5341);
    if ((temp_v0 >= 0) && (temp_v0 < 2)) {
        return arg0 + (temp_v0 * 8) + 0x5344;
    }
    return NULL;
}

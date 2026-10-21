// range: 0x479C50 0x479C60
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00479C50(char *arg0) {
    return arg0 + M2C_FIELD(arg0, s16 *, 2);
}

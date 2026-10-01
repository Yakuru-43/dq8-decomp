// range: 0x479C10 0x479C20
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00479C10(char *arg0) {
    return arg0 + M2C_FIELD(arg0, s16 *, 2);
}

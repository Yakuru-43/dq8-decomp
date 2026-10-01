// range: 0x474F50 0x474F60
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00474F50(char *arg0) {
    return arg0 + M2C_FIELD(arg0, s16 *, 4);
}

// range: 0x474F90 0x474FA0
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00474F90(char *arg0) {
    return arg0 + M2C_FIELD(arg0, s16 *, 4);
}

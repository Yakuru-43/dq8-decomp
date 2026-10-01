// range: 0x310850 0x310870
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00310850(char *arg0, f32 fparg0) {
    char *temp_v1;

    temp_v1 = M2C_FIELD(arg0, char **, 4);
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, f32 *, 0x448) = fparg0;
    }
}

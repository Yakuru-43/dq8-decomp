// range: 0x14E500 0x14E540
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0014E500(s32 arg0, char *arg1) {
    char *temp_a1;

    if (arg1 != NULL) {
        temp_a1 = arg1 - (M2C_FIELD(arg1, s32 *, -4) * 0x10);
        *M2C_FIELD(temp_a1, char ***, 4) = M2C_FIELD(temp_a1, char **, 0);
        M2C_FIELD(M2C_FIELD(temp_a1, char **, 0), char ***, 4) = (char **) M2C_FIELD(temp_a1, char ***, 4);
    }
}

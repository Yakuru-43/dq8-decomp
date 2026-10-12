// range: 0x1813E0 0x181420
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

extern s8 D_003E0428;
extern M2C_UNK *D_003E042C;
extern M2C_UNK D_00409140 __attribute__((section(".data")));

char *func_001813E0(void) {
    M2C_UNK *var_v0;

    if ((1 != D_003E0428) || (var_v0 = D_003E042C, (NULL == var_v0))) {
        var_v0 = &D_00409140;
    }
    return (char *) var_v0 + 0x1700;
}

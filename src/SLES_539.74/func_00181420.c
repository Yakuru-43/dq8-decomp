// range: 0x181420 0x181460
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

extern s8 D_003E0428;
extern M2C_UNK *D_003E042C;
extern M2C_UNK D_00409140 __attribute__((section(".data")));

char *func_00181420(void) {
    M2C_UNK *var_v0;

    if ((D_003E0428 != 1) || (var_v0 = D_003E042C, (var_v0 == NULL))) {
        var_v0 = &D_00409140;
    }
    return (char *) var_v0 + 0x9F0;
}

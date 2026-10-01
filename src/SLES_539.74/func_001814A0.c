// range: 0x1814A0 0x1814D0
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 D_003E0428;
extern M2C_UNK *D_003E042C;
extern M2C_UNK D_00409140 __attribute__((section(".data")));

M2C_UNK *func_001814A0(void) {
    if ((D_003E0428 == 0) && (D_003E042C != NULL)) {
        return D_003E042C;
    }
    return &D_00409140;
}

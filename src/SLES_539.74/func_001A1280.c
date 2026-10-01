// range: 0x1A1280 0x1A12E0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK RotateThreadReadyQueue(s32);                /* extern */
extern s32 D_003DFB8C;

void func_001A1280(void *arg0) {
    s32 var_s0;

    if (M2C_FIELD(arg0, u8 *, 0x17900) != 0) {
        var_s0 = 0;
        do {
            RotateThreadReadyQueue(D_003DFB8C);
            var_s0 += 1;
        } while (var_s0 < 4);
    }
}

// range: 0x1A06C0 0x1A06F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK RotateThreadReadyQueue(s32);                /* extern */
M2C_UNK func_0019F940(M2C_UNK *);                   /* extern */
extern s32 D_003DFB8C;
extern M2C_UNK D_00410DA8 __attribute__((section(".data")));

s32 func_001A06C0(void) {
    RotateThreadReadyQueue(D_003DFB8C);
    func_0019F940(&D_00410DA8);
    return 1;
}

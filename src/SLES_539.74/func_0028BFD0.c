// range: 0x28BFD0 0x28C010
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
M2C_UNK func_0028C5C0(s32, s32, s32);               /* extern */
extern s32 D_003E0E10;
extern s32 D_003E0E14;
extern s32 D_003E0E38;

s32 func_0028BFD0(void) {
    func_0028C5C0(D_003E0E10, func_001667C0(), D_003E0E14);
    D_003E0E38 = 0;
    return 1;
}

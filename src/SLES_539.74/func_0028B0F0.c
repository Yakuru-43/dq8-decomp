// range: 0x28B0F0 0x28B120
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern s32 D_003E0E34;

s32 func_0028B0F0(void) {
    D_003E0E34 = func_001667C0();
    return 1;
}

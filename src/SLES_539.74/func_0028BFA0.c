// range: 0x28BFA0 0x28BFD0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern s32 D_003E0E38;

s32 func_0028BFA0(void) {
    D_003E0E38 = func_001667C0();
    return 1;
}

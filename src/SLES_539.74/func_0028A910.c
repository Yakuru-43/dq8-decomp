// range: 0x28A910 0x28A940
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern s32 D_003E0E3C;

s32 func_0028A910(void) {
    D_003E0E3C = func_001667C0();
    return 1;
}

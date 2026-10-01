// range: 0x28B1C0 0x28B1F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern void *D_003E0E10;

s32 func_0028B1C0(void) {
    M2C_FIELD(D_003E0E10, s32 *, 0xF4) = func_001667C0();
    return 1;
}

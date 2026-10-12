// range: 0x285CA0 0x285CC0
// auto: m2c draft, verified byte-exact
#include "common.h"

extern s32 D_004209E4 __attribute__((section(".data")));
extern char *D_00420A58 __attribute__((section(".data")));

s32 func_00285CA0(void) {
    M2C_FIELD(D_00420A58, s32 *, 0x4DC) = (s32) D_004209E4;
    return 1;
}

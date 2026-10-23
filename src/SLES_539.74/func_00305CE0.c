// range: 0x305CE0 0x305D10
#include "common.h"

s32 func_003763D0(void);                              /* extern */
extern f32 D_003D0100[];

f32 func_00305CE0(void) {
    return D_003D0100[func_003763D0()];
}

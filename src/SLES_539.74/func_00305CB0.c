// range: 0x305CB0 0x305CE0
#include "common.h"

s32 func_00376390(void);                              /* extern */
extern f32 D_003D0100[];

f32 func_00305CB0(void) {
    return D_003D0100[func_00376390()];
}

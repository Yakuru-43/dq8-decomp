// range: 0x18AA70 0x18AAD0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0018ACA0(void);
void func_0019AEC0(char *, s32, s32, f32);
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44], gap at: 0x8. */
void func_0018AA70(char *arg0, s32 arg1, s32 arg2, f32 fparg0) {
    func_0019AEC0(arg0 + 0x68E0, arg1, arg2 * func_0018ACA0(), fparg0);
    M2C_FIELD(arg0, s16 *, 0x6930) = 0;
}

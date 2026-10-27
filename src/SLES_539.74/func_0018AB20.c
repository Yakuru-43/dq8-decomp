// range: 0x18AB20 0x18AB90
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0018ACA0(void);
void func_0019AFC0(char *, s32, f32, f32, f32);
void func_0018AB20(char *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    func_0019AFC0(arg0 + 0x68E0, arg1 * func_0018ACA0(), fparg0, fparg1, fparg2);
    M2C_FIELD(arg0, s16 *, 0x6930) = 0;
}

// range: 0x212500 0x212600
#include "common.h"

f32 func_00166780(s32);                               /* extern */
s32 func_00212790(void);                              /* extern */
s32 func_0013A900(f32);                               /* extern */
s32 func_00129848(s32);                               /* extern */
s32 func_0013ADF8(f64, s32);                          /* extern */
s32 func_00128BF8(s32);                               /* extern */
f32 func_0013B4B8(s32);                               /* extern */
extern char *D_003E0944;
extern f32 D_003DF4B4;
extern f64 D_003DF280;

s32 func_00212500(s32 arg0, s32 arg1) {
    f32 f;
    f32 temp;
    s32 val;

    if (func_00212790() == 0) {
        return 1;
    }
    f = func_00166780(arg0);
    if (arg1 >= 2) {
        temp = D_003DF4B4 * f / 180.0f;
        val = func_0013A900(temp / 2.0f);
        val = func_00129848(val);
        val = func_0013ADF8(D_003DF280, val);
        val = func_00128BF8(val);
        val = func_0013ADF8(2.0, val);
        f = 180.0f * func_0013B4B8(val) / D_003DF4B4;
    }
    M2C_FIELD(D_003E0944, f32 *, 4) = f;
    return 1;
}

// range: 0x37AD10 0x37AD80
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00181420();                                /* extern */
s32 func_00201CD0();                                /* extern */
s32 func_00205D30(s32, s16);                        /* extern */
void *func_00370FA0(s32, M2C_UNK *);                /* extern */
extern M2C_UNK D_003D5450 __attribute__((section(".data")));

s32 func_0037AD10(void) {
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = func_00181420();
    var_v0 = func_00205D30(temp_s0, M2C_FIELD(func_00370FA0(func_00201CD0(), &D_003D5450), s16 *, 0x12));
    if ((var_v0 < 0) || (var_v0 >= 4)) {
        var_v0 = 4;
    }
    return var_v0;
}

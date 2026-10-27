// range: 0x460D70 0x460DE0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_181420();                                  /* extern */
s32 func_201CD0();                                  /* extern */
s32 func_205D30(s32, s16);                          /* extern */
char *func_370FA0(s32, M2C_UNK *);                  /* extern */
extern M2C_UNK D_00478F90 __attribute__((section(".data")));

s32 func_00460D70(char *arg0) {
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = func_181420();
    var_v0 = func_205D30(temp_s0, M2C_FIELD(func_370FA0(func_201CD0(), &D_00478F90), s16 *, 0x12));
    if ((var_v0 < 0) || (var_v0 >= 4)) {
        var_v0 = 4;
    }
    return var_v0;
}

// range: 0x46AA70 0x46AAF0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_181420();                                  /* extern */
s32 func_201CD0();                                  /* extern */
s32 func_202530();                                  /* extern */
s32 func_205C00(s32, s32);                          /* extern */
s32 func_370FA0(s32, M2C_UNK *);                    /* extern */
s32 func_3715D0(s32);                               /* extern */
extern M2C_UNK D_00479360 __attribute__((section(".data")));

s32 func_0046AA70(void) {
    s32 temp_s1;
    s32 var_s0;

    temp_s1 = func_3715D0(func_370FA0(func_201CD0(), &D_00479360));
    var_s0 = func_205C00(func_181420(), temp_s1);
    if ((temp_s1 == func_202530()) || (var_s0 < 0)) {
        var_s0 = 4;
    }
    return var_s0;
}

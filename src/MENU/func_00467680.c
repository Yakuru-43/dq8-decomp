// range: 0x467680 0x467700
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_371260(s32, M2C_UNK);                  /* extern */
s32 func_371490();                                  /* extern */
s32 func_3714E0(s32);                               /* extern */
s32 func_3714F0(s32);                               /* extern */
M2C_UNK func_376130();                              /* extern */
M2C_UNK func_376300(s32, s32);                      /* extern */
M2C_UNK func_37C760();                              /* extern */

s32 func_00467680(s32 arg0) {
    s32 temp_s0;

    if (func_371490() != 0) {
        func_371260(arg0, 1);
        temp_s0 = func_3714F0(arg0) - 0x10;
        func_376300(temp_s0, func_3714E0(arg0) - 0x10);
        func_37C760();
        func_376130();
    }
    return 1;
}

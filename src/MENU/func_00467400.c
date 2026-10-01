// range: 0x467400 0x467490
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_1813D0();                                /* extern */
M2C_UNK func_22AB50(M2C_UNK);                       /* extern */
s32 func_3714E0(s32);                               /* extern */
s32 func_3714F0(s32);                               /* extern */
M2C_UNK func_376130();                              /* extern */
M2C_UNK func_37C2D0(M2C_UNK);                       /* extern */

s32 func_00467400(s32 arg0) {
    s32 temp_s0;
    s32 temp_v0;
    char *temp_s1;

    temp_s1 = func_1813D0();
    temp_s0 = func_3714E0(arg0);
    temp_v0 = func_3714F0(arg0);
    if (temp_s0 == 0) {
        M2C_FIELD(temp_s1, s32 *, 0x18) = temp_v0;
    }
    if (temp_s0 == 1) {
        M2C_FIELD(temp_s1, s32 *, 0x14) = temp_v0;
    }
    if (temp_s0 == 2) {
        M2C_FIELD(temp_s1, s32 *, 0x10) = temp_v0;
    }
    if (temp_s0 == 3) {
        M2C_FIELD(temp_s1, s32 *, 4) = temp_v0;
    }
    func_376130();
    func_37C2D0(4);
    func_22AB50(0);
    return 1;
}

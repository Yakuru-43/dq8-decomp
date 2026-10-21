// range: 0x4677F0 0x467890
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CD0();                                  /* extern */
M2C_UNK func_22AB50(M2C_UNK);                       /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
s32 func_3714E0(s32);                               /* extern */
s32 func_3714F0(s32);                               /* extern */
M2C_UNK func_376270(s32);                           /* extern */
M2C_UNK func_37C2D0(M2C_UNK);                       /* extern */
extern M2C_UNK D_004792C0 __attribute__((section(".data")));

s32 func_004677F0(s32 arg0) {
    s32 temp_v0;

    func_22AB50(0);
    temp_v0 = func_3714E0(arg0);
    if (temp_v0 == 0) {
        func_376270(func_3714F0(arg0));
    }
    if (temp_v0 == 1) {
        func_370C00(func_201CD0(), &D_004792C0, 0);
    }
    func_37C2D0(4);
    return 1;
}

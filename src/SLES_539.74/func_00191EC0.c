// range: 0x191EC0 0x191F90
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0014E240(M2C_UNK, s32);                    /* extern */
s32 func_0014E8A0(s32);                             /* extern */
s32 func_0014EB30(M2C_UNK);                         /* extern */
s32 func_0018D7D0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_0018DCB0(s32, s32, s32);               /* extern */
M2C_UNK func_00191F90(s32, M2C_UNK *);              /* extern */
M2C_UNK func_00191FF0(s32, s32, s32);               /* extern */
M2C_UNK func_00192090(s32);                         /* extern */
extern M2C_UNK D_003C35C0 __attribute__((section(".data")));

void func_00191EC0(s32 arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    s32 temp_s2;
    s32 var_s1;


    if (!(arg2 != 0)) {
        return;
    }

    var_s1 = func_0014EB30(0x58);
    if (var_s1 != 0) {
        var_s1 = func_0014E8A0(var_s1);
    }
    func_00191F90(var_s1, &D_003C35C0);
    temp_s2 = (arg3 >> 4) + 1;
    func_0018DCB0(var_s1, func_0014E240(arg1, temp_s2), temp_s2);
    func_00192090(var_s1);
    func_00191FF0(arg2, arg3, func_0018D7D0(arg0, 5));
}

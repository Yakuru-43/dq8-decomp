// range: 0x176F00 0x176F90
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00236BD0(M2C_UNK *);                   /* extern */
M2C_UNK func_00236C20(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_00416010 __attribute__((section(".data")));

void func_00176F00(char *arg0, s32 arg1) {
    s32 var_a1;


    if (!(arg0 != NULL)) {
        return;
    }

    var_a1 = 1;
    if ((arg0 != NULL) && (M2C_FIELD(arg0, s32 *, 0x200) == 0)) {
        var_a1 = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x20C) == 0) {
        var_a1 = 0;
    }
    if (var_a1 == 0) {

    } else {
        func_00236C20(&D_00416010, var_a1);
        if (arg1 != 0) {
            func_00236BD0(&D_00416010);
        }
    }
}

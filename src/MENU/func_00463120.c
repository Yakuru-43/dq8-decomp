// range: 0x463120 0x463190
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CD0();                                  /* extern */
M2C_UNK func_22AB50(M2C_UNK);                       /* extern */
char *func_359CF0(M2C_UNK *, s32);                  /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
s32 func_371500(s32, M2C_UNK);                      /* extern */
extern M2C_UNK D_00479020 __attribute__((section(".data")));
extern M2C_UNK D_421AD0 __attribute__((section(".data")));

s32 func_00463120(s32 arg0) {
    char *temp_v0;

    func_22AB50(0);
    temp_v0 = func_359CF0(&D_421AD0, *(s32 *)0x458B90);
    M2C_FIELD(temp_v0, s32 *, 0xF0) = 0;
    M2C_FIELD(temp_v0, s32 *, 0xF4) = func_371500(arg0, 1);
    func_370C00(func_201CD0(), &D_00479020, 1);
    return 1;
}

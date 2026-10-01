// range: 0x46CD30 0x46CDC0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0046E170();                                /* extern */
M2C_UNK func_22AB50(M2C_UNK);                       /* extern */
char *func_359CF0(M2C_UNK *, s32);                  /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
s32 func_371500(char *, M2C_UNK);                   /* extern */
M2C_UNK func_37A500(s32, M2C_UNK);                  /* extern */
extern M2C_UNK D_00479460 __attribute__((section(".data")));
extern M2C_UNK D_421AD0 __attribute__((section(".data")));

s32 func_0046CD30(char *arg0) {
    char *temp_v0;

    func_22AB50(0);
    temp_v0 = func_359CF0(&D_421AD0, func_0046E170());
    M2C_FIELD(temp_v0, s32 *, 0xF0) = 0;
    M2C_FIELD(temp_v0, s32 *, 0xF4) = func_371500(arg0, 1);
    func_37A500(M2C_FIELD(temp_v0, s32 *, 0xE0), 0);
    func_370C00(M2C_FIELD(arg0, s32 *, 0x20), &D_00479460, 1);
    return 1;
}

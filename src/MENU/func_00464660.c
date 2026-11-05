// range: 0x464660 0x464710
#include "common.h"

s32 func_181420();                                  /* extern */
s32 func_202530();                                  /* extern */
s32 func_205D30(s32, s32);                          /* extern */
M2C_UNK func_22AB50(M2C_UNK);                       /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
s32 func_3715D0(s32);                               /* extern */
M2C_UNK func_37C110(M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_37CEE0(M2C_UNK);                       /* extern */
extern M2C_UNK D_00479120 __attribute__((section(".data")));
extern s8 D_003E1A3C __attribute__((section(".sdata")));

s32 func_00464660(char *arg0) {
    s32 temp_s1;
    s32 temp_s0;
    s32 var_v0;

    func_22AB50(0);
    temp_s0 = func_202530();
    temp_s1 = func_3715D0(M2C_FIELD(arg0, s32 *, 0x18));
    var_v0 = func_205D30(func_181420(), temp_s1);
    if (temp_s0 <= temp_s1) {
        D_003E1A3C = -1;
    } else {
        D_003E1A3C = var_v0;
    }
    func_37C110(0, 0, 0);
    func_37CEE0(0);
    func_370C00(M2C_FIELD(arg0, s32 *, 0x20), &D_00479120, 0);
    return 1;
}

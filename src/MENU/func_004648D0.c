// range: 0x4648D0 0x464970
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_181420();                                  /* extern */
s32 func_205D30(s32, s32);                          /* extern */
s32 func_2D34C0();                                  /* extern */
M2C_UNK func_2D38E0(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_37D790(M2C_UNK);                       /* extern */
M2C_UNK func_37DD00(s32, M2C_UNK);                  /* extern */
M2C_UNK func_37E170(s32, M2C_UNK);                  /* extern */

void func_004648D0(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_205D30(func_181420(), arg0);
    if ((temp_v0 >= 0) && (temp_v0 < 4)) {
        func_37E170(temp_v0, 0);
    } else {
        func_37E170(4, 0);
    }
    func_2D38E0(func_2D34C0(), 0x49C, 1, -1);
    func_37DD00(temp_v0, 0);
    func_37D790(0);
}

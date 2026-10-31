// range: 0x46A6D0 0x46A7A0
#include "common.h"

M2C_UNK func_0046DDF0();                                    /* extern */
M2C_UNK func_0046DE00();                                    /* extern */
M2C_UNK func_0046A7A0(void *, M2C_UNK);                     /* extern */
M2C_UNK func_2D58C0(M2C_UNK, M2C_UNK, void *, M2C_UNK);     /* extern */
M2C_UNK func_2D65E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_2D7560(M2C_UNK, M2C_UNK, void *, void *);      /* extern */
s32 func_2D57D0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK func_2D7120(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_2D50F0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);    /* extern */

extern M2C_UNK D_00474670 __attribute__((section(".data")));

void func_0046A6D0(s32 arg0) {
    M2C_UNK handle;
    s32 local_3C;
    s32 local_38;
    s32 count;

    handle = func_0046DDF0();
    func_0046DE00();
    func_0046A7A0(&D_00474670, arg0);
    func_2D58C0(handle, 0x1F4F, &D_00474670, 0);
    func_2D65E0(handle, 0x1F4F, 0, 0xDA);
    func_2D7560(handle, 0x1F4E, &local_3C, &local_38);
    count = func_2D57D0(handle, 0x1F4F, 0, 0);
    func_2D7120(handle, 0x1F52, local_3C + 0xDA - (count >> 1), local_38);
    func_2D50F0(handle, 0x1F52, count, 0);
}

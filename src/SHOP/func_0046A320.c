// range: 0x46A320 0x46A410
#include "common.h"

s32 func_0046DDF0();                                     /* extern */
M2C_UNK func_2D57D0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_2D58C0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_2D65E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

s32 func_0046A320(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 temp_a1;
    s32 temp_v1;

    temp_v0 = func_0046DDF0();
    temp_a1 = arg0 + 2;
    func_2D58C0(temp_v0, temp_a1, arg1, 0);
    func_2D65E0(temp_v0, temp_a1, 0, 0x92);
    func_2D58C0(temp_v0, temp_a1, arg2, 1);
    func_2D65E0(temp_v0, temp_a1, 1, 0x92);
    func_2D58C0(temp_v0, temp_a1, arg3, 2);
    func_2D65E0(temp_v0, temp_a1, 2, 0x86);
    temp_v1 = func_2D57D0(temp_v0, temp_a1, 0, 2) >> 1;
    return 0x86 - temp_v1;
}

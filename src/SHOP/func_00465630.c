// range: 0x465630 0x4656D0
#include "common.h"

s32 func_2D34C0();                                                /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);         /* extern */

void func_00465630(s32 arg0) {
    s32 handle;
    u8 inv;
    s32 flag;

    handle = func_2D34C0();
    inv = (u8)((arg0 != 0) ^ 1);
    flag = (u8)((inv != 0) ^ 1);
    func_2D38E0(handle, 0x1778, flag, -1);
    func_2D38E0(handle, 0x1781, flag, -1);
    func_2D38E0(handle, 0x1783, flag, -1);
    func_2D38E0(handle, 0x1785, flag, -1);
}

// range: 0x20D4E0 0x20D600
#include "common.h"

s32 func_0015F490(void);                             /* extern */
M2C_UNK func_00141BF0(s32);                          /* extern */
M2C_UNK func_0013FA20(s32);                          /* extern */
M2C_UNK func_0013E420(s32, M2C_UNK);                 /* extern */
M2C_UNK func_0013E3F0(s32, M2C_UNK);                 /* extern */
M2C_UNK func_0013E390(s32, M2C_UNK);                 /* extern */
M2C_UNK func_0013F6C0(s32, M2C_UNK);                 /* extern */
M2C_UNK func_0013ECD0(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0013EF90(s32, M2C_UNK, M2C_UNK, M2C_UNK);          /* extern */
M2C_UNK func_0013F450(s32);                          /* extern */
M2C_UNK func_00141B00(s32);                          /* extern */

void func_0020D4E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                   s32 arg6, s32 arg7) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = func_0015F490();
    temp_v1 = func_00141BF0(temp_v0);
    func_0013FA20(temp_v1);
    func_0013E420(temp_v1, 1);
    func_0013E3F0(temp_v1, 0);
    func_0013E390(temp_v1, 0);
    func_0013F6C0(temp_v1, 6);
    func_0013ECD0(temp_v1, arg4, arg5, arg6, arg7);
    func_0013EF90(temp_v1, arg0, arg1, 0);
    func_0013EF90(temp_v1, arg0 + arg2, arg1 + arg3, 0);
    func_0013F450(temp_v1);
    func_00141B00(temp_v0);
}

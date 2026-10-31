// range: 0x464D50 0x464DF0
#include "common.h"

M2C_UNK func_37EC50(s32, s32);                                      /* extern */
s32 func_1FFC10(s32);                                               /* extern */
M2C_UNK func_37ECF0(s32, s32, s32, s32, s32);                       /* extern */
M2C_UNK func_2D38E0(s32, s32, s32, s32);                            /* extern */
M2C_UNK func_2D7120(s32, s32, s32, s32);                             /* extern */
extern s32 func_37EB60(s32, s32, s32, s32);

s32 func_00464D50(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 m1;

    func_37EC50(0x273A, 0x95);
    temp_v0 = func_1FFC10(0xC9);
    m1 = -1;
    func_37ECF0(0x273A, temp_v0, m1, m1, 5);
    func_2D38E0(arg1, 0x273A, 1, -1);
    func_2D7120(arg1, 0x273A, 0x72, 0xEA);
    temp_v1 = *(s32 *)(arg0 + 0x18);
    func_37EB60(0x273A, 0x18703, *(s16 *)(temp_v1 + 0x12), 1);
    return 1;
}

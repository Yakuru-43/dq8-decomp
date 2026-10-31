// range: 0x4679B0 0x467A50
#include "common.h"

M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_2D6390(M2C_UNK, s32, s32, s32, s32, s32, s32, f32); /* extern */
M2C_UNK func_3710B0(char *, M2C_UNK, M2C_UNK);                   /* extern */
s32 func_3714E0(void);                                           /* extern */
s32 func_3715E0(s32);                                            /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));

s32 func_004679B0(char *arg0, M2C_UNK arg1) {
    s32 temp_v0;

    if (func_3714E0() != 1) {
        temp_v0 = func_3715E0(M2C_FIELD(arg0, s32 *, 0x18));
        func_2D6390(arg1, 0x58A, 1, 0x18703, temp_v0 * 0x6A - 0x2A, -2, 0,
                    D_003DF744);
    }
    func_2D38E0(arg1, 0x2B82, 0, -1);
    func_3710B0(arg0, 1, 1);
    return 1;
}

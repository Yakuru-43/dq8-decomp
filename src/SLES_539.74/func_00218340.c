// range: 0x218340 0x218390
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003055D0(M2C_UNK);                         /* extern */
extern u8 D_003E0990;
extern s16 D_003E0994;

s32 func_00218340(void) {
    if (D_003E0990 != 0) {
        if (D_003E0994 >= 0xBC) {
            if (func_003055D0(-1) == 0) {
                goto block_6;
            }
            goto block_4;
        }
block_4:
        return 0;
    }
block_6:
    return 1;
}

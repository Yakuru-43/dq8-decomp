// range: 0x1617E0 0x161840
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK DeleteSema(s32);                            /* extern */
extern s32 D_003DFBA8;
extern s32 D_003DFBAC;
extern s32 D_003E031C;

s32 func_001617E0(void) {
    if (D_003DFBA8 >= 0) {
        DeleteSema(D_003DFBA8);
    }
    if (D_003DFBAC >= 0) {
        DeleteSema(D_003DFBAC);
    }
    D_003E031C = 0;
    return 1;
}

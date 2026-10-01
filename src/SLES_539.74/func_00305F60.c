// range: 0x305F60 0x305FC0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK DeleteSema(s32);                            /* extern */
M2C_UNK DeleteThread(s32);                          /* extern */
M2C_UNK TerminateThread(s32);                       /* extern */
extern s32 D_003DFF80;
extern s32 D_003DFF84;

void func_00305F60(void) {
    if (D_003DFF80 >= 0) {
        TerminateThread(D_003DFF80);
        DeleteThread(D_003DFF80);
        D_003DFF80 = -1;
    }
    if (D_003DFF84 >= 0) {
        DeleteSema(D_003DFF84);
        D_003DFF84 = -1;
    }
}

// range: 0x1950B0 0x1951D0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002637C0(M2C_UNK);                     /* extern */
extern s8 D_003E05BC;
extern s16 D_0040FEC0 __attribute__((section(".data")));
extern s8 D_0040FF30 __attribute__((section(".data")));
extern s8 D_0040FF31 __attribute__((section(".data")));
extern s8 D_0040FF32 __attribute__((section(".data")));
extern s32 D_00416250 __attribute__((section(".data")));
extern s16 D_0041627A __attribute__((section(".data")));

void func_001950B0(void) {
    s32 temp_v1;

    D_0040FF30 = 1;
    D_0040FF32 = 0;
    temp_v1 = D_00416250 - 1;
    D_00416250 = temp_v1;
    if (temp_v1 < 0) {
        D_00416250 = 0;
    }
    if (D_00416250 >= 2) {
        D_00416250 = 1;
    }
    D_0041627A -= 1;
    if (D_0041627A < 0) {
        D_0041627A = 0;
    }
    if (D_0041627A >= 2) {
        D_0041627A = 1;
    }
    func_002637C0(0);
    if (D_003E05BC != 0) {
        if (D_0040FEC0 <= 0) {
            D_0040FF32 = 2;
        }
    } else {
        D_0040FF31 = 1;
        D_0040FF30 = 0;
    }
}

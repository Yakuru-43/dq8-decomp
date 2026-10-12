// range: 0x17A7A0 0x17A880
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00208A90();                                /* extern */
M2C_UNK func_00372990(f32, s32);                    /* extern */
extern f32 D_003DF3C4;
extern f32 D_003DF470;
extern f32 D_003DF4D8;
extern f32 D_003DFC18;
extern s8 D_003E0494;

void func_0017A7A0(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_00208A90();

    if (!(temp_v0 != 0)) {
        return;
    }

    D_003E0494 = 0;
    if (arg1 == 0) {
        func_00372990(D_003DFC18, temp_v0);
    }
    if (arg1 == 1) {
        func_00372990(0.75f, temp_v0);
    }
    if (arg1 == 4) {
        func_00372990(D_003DF4D8, temp_v0);
    }
    if (arg1 == 5) {
        func_00372990(D_003DF3C4, temp_v0);
    }
    if (arg1 == 3) {
        func_00372990(D_003DF470, temp_v0);
    }
}

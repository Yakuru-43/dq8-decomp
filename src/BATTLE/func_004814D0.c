// range: 0x4814D0 0x481520
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s32 func_004814D0(s32 arg0, char *arg1) {
    s32 temp_v0;
    char *temp_v0_2;

    if (arg1 == NULL) {
        return 1;
    }
    temp_v0 = M2C_FIELD(arg1, s32 *, 0xB4);
    if (temp_v0 == 0) {
        return 1;
    }
    temp_v0_2= (char *) ( temp_v0 + 8);
    if (temp_v0_2 == NULL) {
        return 1;
    }
    M2C_FIELD(arg1, f32 *, 0xA4)= (f32) (2.0f * M2C_FIELD(temp_v0_2, f32 *, 4));
    return 0;
}

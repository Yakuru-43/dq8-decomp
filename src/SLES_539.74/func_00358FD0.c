// range: 0x358FD0 0x359010
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00358FD0(s32 arg0) {
    s32 temp_a1;
    s32 var_t0;
    char *temp_a2;

    var_t0 = 0;
    do {
        temp_a2= (char *) ( arg0 + (var_t0 * 0x590));
        temp_a1 = M2C_FIELD(temp_a2, s32 *, 8);
        if (M2C_FIELD(temp_a2, s32 *, 0) != temp_a1) {
            M2C_FIELD(temp_a2, s32 *, 0) = temp_a1;
        }
        var_t0 += 1;
    } while (var_t0 < 0x20);
}

// range: 0x308710 0x308740
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00308710(s32 arg0, s32 arg1) {
    u16 *temp_a1;
    u16 temp_a0;

    temp_a1= (unsigned short *) ( arg0 + (arg1 * 2));
    temp_a0 = *temp_a1;
    if ((s32) temp_a0 < 0x64) {
        *temp_a1 = temp_a0 + 1;
    }
}

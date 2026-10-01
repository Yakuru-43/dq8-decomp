// range: 0x200E70 0x200EE0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001979F0();                                /* extern */
s32 func_001D6EC0();                                /* extern */
s32 func_00263850();                                /* extern */
s32 func_00350E60();                                /* extern */

s32 func_00200E70(void) {
    s32 var_s0;

    var_s0 = 1;
    if (func_001979F0() != 0) {
        var_s0 = 0;
    }
    if (func_001D6EC0() != 0) {
        var_s0 = 0;
    }
    if (func_00350E60() != 0) {
        var_s0 = 0;
    }
    if (func_00263850() != 0) {
        var_s0 = 0;
    }
    return var_s0;
}

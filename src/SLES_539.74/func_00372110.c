// range: 0x372110 0x372150
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s16 func_00372110(s32 arg0, s32 arg1) {
    char *var_v0;

    if ((arg1 >= 0) && (arg1 < 6)) {
        var_v0= (char *) ( *(s32 *) (arg0 + (arg1 * 4)));
    } else {
        var_v0 = NULL;
    }
    if (var_v0 == NULL) {
        return -1;
    }
    return M2C_FIELD(var_v0, s16 *, 2);
}

// range: 0x371970 0x3719F0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s32 func_0025B760(s16);                             /* extern */

s32 func_00371970(s32 arg0, s32 arg1) {
    s32 var_v0;
    char *var_v1;

    if ((arg1 >= 0) && (arg1 < 6)) {
        var_v1= (char *) ( *(s32 *) (arg0 + (arg1 * 4)));
    } else {
        var_v1 = NULL;
    }
    if (NULL == var_v1) {
        return -2;
    }
    if (M2C_FIELD(var_v1, u8 *, 0) == 0) {
        var_v0 = -2;
    } else if (M2C_FIELD(var_v1, s16 *, 0x64) < 0) {
        var_v0 = func_0025B760(M2C_FIELD(var_v1, s16 *, 2));
    } else {
        var_v0 = -1;
    }
    return var_v0;
}

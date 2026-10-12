// range: 0x2237B0 0x223800
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

extern s16 *D_003E0A20;

char *func_002237B0(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if (NULL == D_003E0A20) {
        return NULL;
    }
    if ((var_a0 < 0) || (*D_003E0A20 < var_a0)) {
        var_a0 = 0;
    }
    return (char *) D_003E0A20 + (var_a0 * 0xC) + 0x24;
}

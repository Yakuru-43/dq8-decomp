// range: 0x372F10 0x372F50
#include "common.h"

s32 *func_00372F10(char *arg0, s32 arg1) {
    char *var_v0;
    s32 temp_v1;

    var_v0 = *(char **)(arg0 + 0xC);
    if (var_v0 == NULL) {
        return NULL;
    }
    temp_v1 = *(s32 *)var_v0;
    while (temp_v1 > 0) {
        if (temp_v1 == arg1) {
            return (s32 *)var_v0;
        }
        var_v0 += 8;
        temp_v1 = *(s32 *)var_v0;
    }
    return NULL;
}

// range: 0x145330 0x145360
#include "common.h"

s32 func_00145330(char *arg0) {
    char *temp_a0;
    s32 temp_v0;
    s32 var_v1;

    temp_a0 = *(char **)(arg0 + 0x270);
    temp_v0 = *(s32 *)(temp_a0 + 8);
    var_v1 = temp_v0 / 2;
    return *(s32 *)(temp_a0 + 0x10) - var_v1;
}

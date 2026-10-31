// range: 0x15C090 0x15C0D0
#include "common.h"

s32 func_0015C090(char *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 *var_a2;
    s32 *var_a3;
    char *var_v1;

    var_a2 = arg2;
    var_a3 = arg3;
    var_v1 = *(char **)(arg0 + 0x130);

    while (var_v1 != 0) {
        *var_a2 = *(s32 *)(var_v1 + 0xC);
        var_a2 += 1;
        *var_a3 = *(s32 *)(var_v1 + 0x10);
        var_v1 = *(char **)(var_v1 + 0);
        var_a3 += 1;
    }

    *var_a2 = -1;
    return 0;
}

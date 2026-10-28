// range: 0x1F8990 0x1F89D0
#include "common.h"

s32 func_001F8990(char *arg0) {
    char *var_v1;

    var_v1 = *(char **)(arg0 + 0x94);
    while (var_v1 != 0) {
        if (*(s32 *)(*(char **)(var_v1 + 0x10) + 0x78) & 0x10) {
            return 1;
        }
        var_v1 = *(char **)(var_v1 + 0);
    }
    return 0;
}

// range: 0x326690 0x3266F0
#include "common.h"

M2C_UNK func_00320FE0(s32, s32);
s32 func_0031E420(s32);

s32 func_00326690(char *arg0) {
    char *var_v0;
    char *inter;
    s32 tmp;

    var_v0 = *(char **)(arg0 + 8);
    var_v0 = var_v0 != NULL ? var_v0 : NULL;
    if (var_v0 == NULL) {
        return -1;
    }
    inter = *(char **)(var_v0 + 0x2C);
    tmp = func_0031E420(*(s32 *)(inter + 8));
    func_00320FE0(*(s32 *)(arg0 + 4), *(s32 *)tmp);
    return 0;
}

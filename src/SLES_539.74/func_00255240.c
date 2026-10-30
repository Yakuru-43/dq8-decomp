// range: 0x255240 0x2552C0
#include "common.h"

extern s32 func_00133F78(s32, s32);
extern void func_001E9F50(char *, M2C_UNK);
extern char *D_003E0C38;

s32 func_00255240(s32 arg0, M2C_UNK arg1) {
    char *var_s1;
    char *var_s0;

    var_s1 = D_003E0C38;
    while (var_s1 != NULL) {
        var_s0 = var_s1 + 0x10;
        if (func_00133F78(*(s32 *)(var_s1 + 0x4C), arg0) == 0) {
            func_001E9F50(var_s0, arg1);
            return 1;
        }
        var_s1 = *(char **)var_s1;
    }
    return 0;
}

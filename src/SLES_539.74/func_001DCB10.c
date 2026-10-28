// range: 0x1DCB10 0x1DCB50
#include "common.h"

extern char *D_003E0734;

s32 func_001DCB10(char *arg0, s32 arg1) {
    s32 new_var;
    if (arg1 != 1) {
        return 0;
    }
    new_var = *(s32 *)(*(char **)(D_003E0734 + 4) + 0x44B0);
    if (*(s32 *)arg0 == 3) {
        *(s32 *)(*(char **)(arg0 + 4) + 4) = new_var;
    }
    return 1;
}

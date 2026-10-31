// range: 0x37B390 0x37B3E0
#include "common.h"

s32 func_00372580(char *);

s32 func_0037B390(s32 arg0, s32 arg1) {
    s32 ret;
    char *temp_a0;

    if (arg1 >= 0) {
        if (arg1 < 4) {
            temp_a0 = *(char **)(arg0 + (arg1 * 4));
            if (temp_a0 != 0) {
                ret = func_00372580(temp_a0);
            } else {
                ret = 0;
            }
            return ret;
        }
    }
    return 0;
}

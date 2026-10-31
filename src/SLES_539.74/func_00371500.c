// range: 0x371500 0x371550
#include "common.h"

s32 func_003715D0(char *);
s32 func_003715E0(char *);

s32 func_00371500(char *arg0, s32 arg1) {
    char *temp_a0;

    temp_a0 = *(char **)((char *)arg0 + 0x18);
    if (temp_a0 == 0) {
        return 0;
    }
    if (arg1 == 0) {
        return func_003715E0(temp_a0);
    }
    if (arg1 == 1) {
        return func_003715D0(temp_a0);
    }
    return 0;
}

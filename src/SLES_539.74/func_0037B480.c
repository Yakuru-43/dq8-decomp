// range: 0x37B480 0x37B4D0
#include "common.h"

s32 func_00372590(s32);

s32 func_0037B480(char *arg0, s32 arg1) {
    s32 val;

    if (arg1 < 0 || arg1 >= 4) {
        return -2;
    }
    val = *(s32 *)(arg0 + (arg1 * 4));
    if (val != 0) {
        return func_00372590(val);
    }
    return -2;
}

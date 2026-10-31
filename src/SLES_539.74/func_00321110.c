// range: 0x321110 0x321160
#include "common.h"

s32 func_00321110(char *arg0, s32 arg1) {
    s32 *base;
    s32 idx;
    s32 val;

    idx = *(s32 *)(arg0 + 8) + arg1 - 1;
    base = (s32 *)((char *)*(char **)(arg0 + 4) + (idx << 3));
    val = base[0];
    if (val == 0) {
        return base[1];
    }
    if (val == 1) {
        return (s32)*(f32 *)(base + 1);
    }
    return 0;
}

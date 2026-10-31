// range: 0x1BFE80 0x1BFED0
#include "common.h"

s32 func_00189AF0(s32);
extern s32 D_003E0664;

s32 func_001BFE80(char *arg0) {
    char *temp_v1;
    f32 var_f0;

    temp_v1 = (char *)func_00189AF0(D_003E0664) + 0x70;
    if (*(s32 *)(arg0 + 0) == 0) {
        var_f0 = (f32)*(s32 *)(arg0 + 4);
    } else {
        var_f0 = *(f32 *)(arg0 + 4);
    }
    *(f32 *)(temp_v1 + 0x198) = var_f0;
    return 1;
}

// range: 0x2E5300 0x2E5350
#include "common.h"

void func_002E5300(char *arg0, s8 arg1, f32 *arg2) {
    f32 t3, t2, t1, t0;
    t0 = arg2[0];
    t1 = arg2[1];
    t2 = arg2[2];
    t3 = arg2[3];
    *(s8 *)(arg0 + 0x1E78) = arg1;
    *(s32 *)(arg0 + 0x1E7C) = *(s32 *)&t0;
    *(s32 *)(arg0 + 0x1E80) = *(s32 *)&t1;
    *(s32 *)(arg0 + 0x1E84) = *(s32 *)&t2;
    *(s32 *)(arg0 + 0x1E88) = *(s32 *)&t3;
}

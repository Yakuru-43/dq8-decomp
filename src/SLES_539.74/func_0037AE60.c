// range: 0x37AE60 0x37AF90
#include "common.h"

extern s32 func_002B0B10(void);
extern s32 func_003053F0(void);
extern s32 func_00307780(void);

s32 func_0037AE60(s32 *arg0, s32 *arg1) {
    s32 var_s0;
    s32 var_v1;
    s32 ret;

    *arg0 = 0xA;
    if (arg1 != 0) {
        var_v1 = 0;
        do {
            arg1[var_v1] = var_v1;
            var_v1++;
        } while (var_v1 < 0xA);
    }

    ret = func_002B0B10();
    if (ret == 3) {
        var_s0 = 0xA2;
        *arg0 = 9;
        if (arg1 != 0) {
            arg1[9] = -1;
        }
    } else {
        ret = func_00307780();
        if (0 < ret) {
            var_s0 = 0xA1;
            *arg0 = 8;
            if (arg1 != 0) {
                arg1[8] = -1;
            }
        } else {
            var_s0 = 0xA0;
            *arg0 = 7;
            if (arg1 != 0) {
                arg1[7] = -1;
            }
        }
    }

    if (func_003053F0() != 0) {
        var_s0 = 0x6F;
        *arg0 = 5;
        if (arg1 != 0) {
            arg1[0] = 0;
            arg1[1] = 1;
            arg1[2] = 5;
            arg1[3] = 2;
            arg1[4] = 4;
            arg1[5] = -1;
        }
    }

    return var_s0;
}

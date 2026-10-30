// range: 0x35BF30 0x35BFE0
#include "common.h"

s32 func_00201740(char *, s32 *);
s32 func_0035BDC0(char *, u32);

s32 func_0035BF30(char *arg0, char *arg1) {
    s32 temp_v0;
    s32 temp_s0;

    if (arg1 == 0) {
        return 0;
    }
    temp_s0 = func_0035BDC0(arg0, (u32)(u8)arg1[0]);
    temp_v0 = func_00201740(arg0, 0);
    if (temp_s0 < 0xFF) {
        if (temp_v0 < temp_s0) {
            return 0;
        }
    }
    if (temp_s0 > 0) {
        if (temp_v0 == 0) {
            return 0;
        }
    }
    if ((u8)arg1[0xF] == 0x2F) {
        if (temp_v0 == 0) {
            return 0;
        }
    }
    return 1;
}

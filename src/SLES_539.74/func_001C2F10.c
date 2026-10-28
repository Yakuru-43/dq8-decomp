// range: 0x1C2F10 0x1C2F60
#include "common.h"

s32 func_001745A0(s32, s32, s32);
extern s32 D_003E1148;

s32 func_001C2F10(char *arg0) {
    s32 value;
    f32 tmp;

    if (*(s32 *)arg0 == 1) {
        tmp = *(f32 *)(arg0 + 4);
        value = (s32)tmp;
    } else {
        value = *(s32 *)(arg0 + 4);
    }
    if (value < 0) {
        return 0;
    }
    func_001745A0(D_003E1148, value, 0);
    return 1;
}

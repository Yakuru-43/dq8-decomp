// range: 0x1C6770 0x1C67B0
#include "common.h"

M2C_UNK func_001A62B0(s32, s32);
extern s32 D_003E06F4;

s32 func_001C6770(char *arg0) {
    s32 a1;
    f32 tmp;

    if (*(s32 *)arg0 == 1) {
        tmp = *(f32 *)(arg0 + 4);
        a1 = (s32)tmp;
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_001A62B0(D_003E06F4, a1);
    return 1;
}

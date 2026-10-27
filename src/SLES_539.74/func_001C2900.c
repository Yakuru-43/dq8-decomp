// range: 0x1C2900 0x1C2940
#include "common.h"

M2C_UNK func_0020B760(s32, s32);
extern s32 D_003E0664;

s32 func_001C2900(char *arg0) {
    s32 a1;
    f32 tmp;

    if (*(s32 *)arg0 == 1) {
        tmp = *(f32 *)(arg0 + 4);
        a1 = (s32)tmp;
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_0020B760(D_003E0664, a1);
    return 1;
}

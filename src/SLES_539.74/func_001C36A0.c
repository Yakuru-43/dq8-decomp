// range: 0x1C36A0 0x1C36E0
#include "common.h"

void func_0020C2D0(s8 *, s32);
extern s8 *D_003E0664;

s32 func_001C36A0(char *arg0) {
    s32 a1;
    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_0020C2D0(D_003E0664, a1);
    return 1;
}

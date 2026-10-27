// range: 0x1BB740 0x1BB780
#include "common.h"

void func_0018C5A0(s32, s32);
extern s32 D_003E0664;

s32 func_001BB740(char *arg0) {
    s32 a1;
    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_0018C5A0(D_003E0664, a1);
    return 1;
}

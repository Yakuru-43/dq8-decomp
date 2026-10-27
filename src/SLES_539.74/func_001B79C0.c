// range: 0x1B79C0 0x1B7A00
#include "common.h"

s32 func_0018CA00(char *, s32);
extern s8 *D_003E0664;

s32 func_001B79C0(char *arg0) {
    s32 a1;
    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_0018CA00((char *)D_003E0664, a1);
    return 1;
}

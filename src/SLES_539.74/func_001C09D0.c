// range: 0x1C09D0 0x1C0A30
#include "common.h"

M2C_UNK func_0020A4A0(s32, s32, s32);
extern s32 D_003E0664;

s32 func_001C09D0(char *arg0) {
    s32 a1;
    s32 a2;

    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(float *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    if (*(s32 *)(arg0 + 8) == 1) {
        a2 = (s32)*(float *)(arg0 + 0xC);
    } else {
        a2 = *(s32 *)(arg0 + 0xC);
    }
    func_0020A4A0(D_003E0664, a1, a2);
    return 1;
}

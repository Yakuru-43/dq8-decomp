// range: 0x1BB870 0x1BB8D0
#include "common.h"

M2C_UNK func_0016B1F0(s32, s32, s32, s32);
extern s32 D_003E0664;

s32 func_001BB870(char *arg0) {
    s32 a2;
    s32 a3;

    if (*(s32 *)arg0 == 1) {
        a2 = (s32)*(float *)(arg0 + 4);
    } else {
        a2 = *(s32 *)(arg0 + 4);
    }
    if (*(s32 *)(arg0 + 8) == 1) {
        a3 = (s32)*(float *)(arg0 + 0xC);
    } else {
        a3 = *(s32 *)(arg0 + 0xC);
    }
    func_0016B1F0(D_003E0664, 1, a2, a3);
    return 1;
}

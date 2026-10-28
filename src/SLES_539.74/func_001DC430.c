// range: 0x1DC430 0x1DC490
#include "common.h"

M2C_UNK func_0016B1F0(s32, s32, s32, s32);
extern s32 D_003E0734;

s32 func_001DC430(char *arg0) {
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
    func_0016B1F0(*(s32 *)(D_003E0734 + 4), 1, a2, a3);
    return 1;
}

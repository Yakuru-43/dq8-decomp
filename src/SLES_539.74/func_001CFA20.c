// range: 0x1CFA20 0x1CFA60
#include "common.h"

M2C_UNK func_0016BC30(s32, s32);
extern s32 D_003E0664;

s32 func_001CFA20(char *arg0) {
    s32 val;

    if (*(s32 *)arg0 == 1) {
        val = (s32)*(float *)(arg0 + 4);
    } else {
        val = *(s32 *)(arg0 + 4);
    }
    func_0016BC30(D_003E0664, val);
    return 1;
}

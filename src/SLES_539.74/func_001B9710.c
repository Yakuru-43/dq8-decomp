// range: 0x1B9710 0x1B9770
#include "common.h"

M2C_UNK func_001D6D10(s32, s32, s32);

s32 func_001B9710(char *arg0) {
    s32 a2;
    s32 a1;

    if (*(s32 *)arg0 == 1) {
        a2 = (s32)*(float *)(arg0 + 4);
    } else {
        a2 = *(s32 *)(arg0 + 4);
    }
    if (*(s32 *)(arg0 + 8) == 1) {
        a1 = (s32)*(float *)(arg0 + 0xC);
    } else {
        a1 = *(s32 *)(arg0 + 0xC);
    }
    func_001D6D10(a2, a1, a2);
    return 1;
}

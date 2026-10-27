// range: 0x1C7750 0x1C7790
#include "common.h"

M2C_UNK func_001A70E0(s32, s32);                    /* extern */
extern s32 D_003E06F4;

s32 func_001C7750(char *arg0) {
    s32 flag = *(s32 *)arg0;
    s32 a1;
    if (flag == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_001A70E0(D_003E06F4, a1);
    return 1;
}
